# Lists

# Odd numbers
odd_numbers = []

for i in range(0, 20):
    if (i % 2 != 0):
        odd_numbers.append(i)
print(odd_numbers)

# Slice
numbers = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
print(numbers)
print(numbers[-3:1])

champions = ['Thrundar', 'Morgate', 'Gandolfo', 'Thraine', 'Norwad', 'Gilforn']
print(champions[:-2])

# Concatenate
def concatenate_favorites(favorite_weapons, favorite_armor, favorite_items):
    return favorite_weapons + favorite_armor + favorite_items

print(concatenate_favorites(
    ['sword', 'dagger'],
    ['bracers', 'helmet'],
    ['feather', 'iron bars']
))

# Contains
def is_top_weapon(weapon):
    top_weapons = [
        "sword of justice",
        "sword of slashing",
        "stabby daggy",
        "great axe",
        "silver bow",
        "spellbook",
        "spiked knuckles",
    ]

    # don't touch above this line

    return weapon in top_weapons

# Filtered Messages

messages = ['well dang it', 'dang the whole dang thing', 'kill that knight, dang it', 'get him!', 'donkey kong', 'oh come on, get them', 'run away from the dang baddies']

def filter_messages(messages):
    filtered_messages = []
    words_removed = []
    
    for message in messages:
        counter = 0
        filtered_words = []
        splited_message = message.split()
        for i in range(0, len(splited_message)):
            if splited_message[i].casefold() == "dang":
                counter += 1
            else:
                filtered_words.append(splited_message[i])

        filtered_message = " ".join(filtered_words) 
        filtered_messages.append(filtered_message)
        words_removed.append(counter)

    return filtered_messages, words_removed

print(filter_messages(messages))

def count_enemies(enemy_names):
    result = {}
    for enemy in enemy_names:
        if enemy in result:
            result[enemy] += 1
        else:
            result[enemy] = 1

    return result


def get_most_common_enemy(enemies_dict):
    name = None
    max_so_far = float("-inf")

    for enemy in enemies_dict:
        if enemies_dict[enemy] > max_so_far:
            name = enemy
            max_so_far = enemies_dict[enemy]
            
    return name
