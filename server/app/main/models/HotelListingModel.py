from .. import db


# hotel category datbase model for Hotel listing
class HotelCategoryModel(db.Model):

    __tablename__ = "category"

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(70), nullable=False)
    tag = db.Column(db.String(255), nullable=False)


# hotel datbase model for Hotel listing
class HotelModel(db.Model):

    __tablename__ = "hotel"

    id = db.Column(db.Integer, primary_key=True)
    category_id = db.Column(db.Integer, db.ForeignKey(
        'category.id'), nullable=False)
    name = db.Column(db.String(255), nullable=False)
    description = db.Column(db.Text, nullable=False)
    amenities = db.Column(db.JSON, nullable=False)
    hotel_policy = db.Column(db.JSON, nullable=False)
    collection = db.Column(db.JSON, nullable=False)
    rooms = db.Column(db.JSON, nullable=False)
    checkin_features = db.Column(db.String(255), nullable=False)
    accomodation_type = db.Column(db.JSON, nullable=False)
    created_at = db.Column(db.DateTime, nullable=False)
    updated_at = db.Column(db.DateTime, nullable=False)
    is_deleted = db.Column(db.Boolean, nullable=False)
    images = db.Column(db.JSON, nullable=False)
