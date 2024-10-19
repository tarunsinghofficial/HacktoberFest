
ingredient_conversions = {
    'flour': 120,     
    'sugar': 200,     
    'butter': 227,   
    'milk': 240,      
   
}


unit_conversions = {
    'cup': 1,
    'tablespoon': 16,    
    'teaspoon': 48,      
    'gram': 1            
}

def convert_ingredient(quantity, from_unit, to_unit, ingredient):
    if ingredient not in ingredient_conversions:
        return "Ingredient not found in database."

   
    if from_unit in unit_conversions:
        quantity_in_cups = quantity / unit_conversions[from_unit]
    else:
        return f"Unsupported 'from' unit: {from_unit}"

    
    quantity_in_grams = quantity_in_cups * ingredient_conversions[ingredient]

   
    if to_unit == 'gram':
        return f"{quantity} {from_unit} of {ingredient} is approximately {quantity_in_grams:.2f} grams."
    elif to_unit in unit_conversions:
        quantity_in_to_unit = quantity_in_grams / ingredient_conversions[ingredient] * unit_conversions[to_unit]
        return f"{quantity} {from_unit} of {ingredient} is approximately {quantity_in_to_unit:.2f} {to_unit}."
    else:
        return f"Unsupported 'to' unit: {to_unit}"


quantity = 1
from_unit = 'cup'
to_unit = 'gram'
ingredient = 'flour'

print(convert_ingredient(quantity, from_unit, to_unit, ingredient))
