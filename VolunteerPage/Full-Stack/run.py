from models import db, User
from app import create_app

# Create the Flask application
app = create_app()

# Use the application context
with app.app_context():
    db.create_all()

# Instructions for running the application
print("Setup complete. You can now run the application with 'flask run'.")