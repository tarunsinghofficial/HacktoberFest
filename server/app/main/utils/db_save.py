from app.main import db


# to commit to database,if any error accur rollback databse to previous state
def db_save(data):
    try:
        db.session.add(data)
        db.session.commit()
        return True
    except Exception as e:
        db.session.rollback()
        return False
