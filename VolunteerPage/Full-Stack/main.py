from flask import Blueprint, render_template, redirect, url_for, request, flash
from werkzeug.security import generate_password_hash, check_password_hash
from models import User
from app import db
from flask_login import login_user, login_required, logout_user

# Create a Blueprint for main routes
main = Blueprint('main', __name__)

@main.route('/')
def index():
    # Render the index page
    return render_template('home.html')

@main.route('/login')
def login():
    return render_template('login.html')

@main.route('/login', methods=['POST'])
def login_post():
 
    # Get form inputs
    email = request.form.get('email')  
    password = request.form.get('password')  
    remember = True if request.form.get('remember') else False

    user = User.query.filter_by(email=email).first()

    # Validate user existence and password
    if not user or not check_password_hash(user.password, password):
        flash('Please check your login details and try again.')
        return redirect(url_for('main.login'))

        # Successful login
    login_user(user, remember=remember)
    
    # Redirect based on role
    return redirect(url_for('main.index'))  # Admin dashboard route

@main.route('/signup')
def signup():
    return render_template('signup.html')

@main.route('/signup', methods=['POST'])
def signup_post():
    """
    Handle the signup form submission.

    This function processes the signup form data, checks if the user already exists,
    creates a new user, and if the user is a patient, creates a patient profile.

    Returns:
        Redirect: Redirects to the signup page if the email already exists,
                  otherwise redirects to the login page after successful signup.
    """
    email = request.form.get('email')
    name = request.form.get('name')
    password = request.form.get('password')

    user = User.query.filter_by(email=email).first()

    if user:
        flash('Email address already exists')
        return redirect(url_for('main.signup'))

    # Create a new user
    new_user = User(email=email, name=name, password=generate_password_hash(password))

    db.session.add(new_user)
    db.session.commit()

    return redirect(url_for('main.login'))


@main.route('/logout')
@login_required
def logout():
    logout_user()
    return redirect(url_for('main.index'))

@main.route('/view_patients', methods=['GET'])
@login_required
def view_patients():
    return render_template('view_patients.html')

