from ..models.HotelListingModel import HotelCategoryModel, HotelModel
from app.main import db
from app.main.settings import key
import jwt
import datetime
from ..utils.db_save import db_save
import math
import json


# register user if email is not present in the users table
def hotel_listing(params):
    per_page = 20

    query = "select h.name as name,h.images->>'$[0]' as images,h.rooms->>'$' as rooms,created_at,updated_at, h.collection->>'$[0]' as collection,c.name as category,c.tag as tag,h.accomodation_type->>'$[0]' as acc_type,h.amenities as amenities,checkin_features as c_f from hotel as h join category as c on h.category_id=c.id WHERE"
    base_query = "select h.collection->>'$[0]' as collection,c.name as category,c.tag as tag,h.accomodation_type->>'$[0]' as acc_type,h.amenities as amenities,checkin_features as c_f from hotel as h join category as c on h.category_id=c.id limit 1"
    count_query = 'select count(h.id) from hotel as h join category as c on h.category_id=c.id WHERE'

    if params.get('collections'):
        collections = list(map(str, params.get('collections').split('&')))
        for item in collections:
            query = query + \
                "  h.collection->>'$[0].%s'=" % (item)+'"true"'+" AND"
            count_query = count_query + \
                "  h.collection->>'$[0].%s'=" % (item)+'"true"'+" AND"
    if params.get('category'):
        category = list(map(str, params.get('category').split('&')))
        for item in category:
            query = query + "  c.name='%s' AND" % (item)
            count_query = count_query + "  c.name='%s' AND" % (item)
    if params.get('accomodation_type'):
        accomodation_type = list(
            map(str, params.get('accomodation_type').split('&')))
        for item in accomodation_type:
            query = query + \
                "  h.accomodation_type->>'$[0].%s'=" % (item)+'"true"'+" AND"
            count_query = count_query + \
                "  h.accomodation_type->>'$[0].%s'=" % (
                    item) + '"true"' + " AND"

    if params.get('amenities'):
        amenities = list(
            map(str, params.get('amenities').split('&')))
        for item in amenities:
            query = query + \
                "  h.amenities->>'$[0].%s'=" % (item)+'"true"'+" AND"
            count_query = count_query + \
                "  h.amenities->>'$[0].%s'=" % (item)+'"true"'+" AND"
    if params.get('checkin_features'):
        checkin_features = list(
            map(str, params.get('checkin_features').split('&')))
        for item in checkin_features:
            query = query + "  h.checkin_features='%s'" % (item)
            count_query = count_query + \
                "   h.checkin_features='%s'" % (item)

    query = query.strip('AND')
    query = query.strip('WHERE')

    count_query = count_query.strip('AND')
    count_query = count_query.strip('WHERE')

    if params.get('page'):
        page = params.get('page')
        offset = (int(page)-1)*per_page
        current_items = int(page)*per_page
        query = query + " Limit %d, %d" % (offset, per_page)
    else:
        query = query + " Limit %d" % (per_page)

    query = query + ';'
    count_query = count_query + ';'
    count_raw = db.engine.execute(count_query)

    for row in count_raw:
        total_results = row[0]
        total_pages = int(math.ceil((row[0]/per_page)))

    print(query)
    data_raw = db.engine.execute(query)
    data_base = db.engine.execute(base_query)

    print(data_raw)

    data = []

    for hotel in data_raw:
        temp_dict = {}
        temp_dict['name'] = hotel['name']
        temp_dict['created_at'] = str(hotel['created_at'])
        temp_dict['updated_at'] = str(hotel['updated_at'])
        temp_dict['rooms'] = json.loads(hotel['rooms'])
        temp_dict['collections'] = json.loads(hotel['collection'])
        temp_dict['category'] = {
            "name": hotel['category'], "tag": hotel['tag']}
        temp_dict['images'] = {
            "large": json.loads(hotel['images'])['large'].split("#"), "medium": json.loads(hotel['images'])['medium'].split("#"), "thumb": json.loads(hotel['images'])['thumb'].split("#")}
        temp_dict['accomodation_type'] = json.loads(hotel['acc_type'])
        temp_dict['amenities'] = json.loads(hotel['amenities'])
        temp_dict['checkin_features'] = hotel['c_f']
        data.append(temp_dict)

    return data, total_pages, total_results
