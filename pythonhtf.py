import datetime

def has_friday_13(month, year):
    day = datetime.date(year, month, 13)
    return day.weekday() == 4

print(has_friday_13(10, 2025))
