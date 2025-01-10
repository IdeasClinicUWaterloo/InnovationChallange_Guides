from flask import Flask, jsonify
from flask_sqlalchemy import SQLAlchemy
import os
from models import db
from flask_login import LoginManager

basedir = os.path.abspath(os.path.dirname(__file__))

# Initialize SQLAlchemy so we can use it later in our models
def create_app():
    """
    Create and configure the Flask application.
    This function sets up the Flask application with necessary configurations,
    initializes extensions, and registers blueprints.
    Configurations:
    - SECRET_KEY: Secret key for session management.
    - SQLALCHEMY_DATABASE_URI: URI for the SQLAlchemy database.
    - DEBUG: Enable or disable debug mode.
    Blueprints:
    - auth: Handles authentication-related routes.
    - main: Handles main application routes.
    - patients: Handles patient-related routes.
    Extensions:
    - SQLAlchemy: Initializes the database with the app.
    - LoginManager: Manages user login sessions.
    Returns:
        Flask app: The configured Flask application instance.
    """
    app = Flask(__name__)

    # Set the secret key for session management
    app.config['SECRET_KEY'] = 'secret-key-goes-here'
    # Configure the SQLAlchemy database URI
    app.config['SQLALCHEMY_DATABASE_URI'] = os.environ.get('DATABASE_URI') \
        or 'sqlite:///' + os.path.join(basedir, 'app.db')
    # Enable debug mode
    app.config['DEBUG'] = True

    # Initialize the database with the app
    db.init_app(app)

    # Register the main blueprint
    from main import main as main_blueprint
    app.register_blueprint(main_blueprint)

    # Initialize the login manager
    login_manager = LoginManager()
    # Set the login view
    login_manager.login_view = 'main.login'
    # Configure the login manager with the app
    login_manager.init_app(app)

    from models import User

    @login_manager.user_loader
    def load_user(user_id):
        # Load the user by ID
        return User.query.get(int(user_id))

    return app

# Run the application if this file is executed directly
if __name__ == '__main__':
    # Create the Flask application
    app = create_app()
    # Run the app in debug mode
    app.run(debug=True)
