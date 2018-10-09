#!/usr/bin/python3
"""
    This is a module that will export to JSON.
"""
from json import dump
from requests import get
from sys import argv


def export_to_json():
    """
        This will export our data to JSON format and record all tasks owned
        by this employee.
    """

    with open("todo_all_employees.json", "w") as json_file:
        final_dict = {}
        for users in get("https://jsonplaceholder.typicode.com/users").json():
            emptylist = []
            final_dict[users["id"]] = emptylist
            for todo in get("https://jsonplaceholder.typicode.com/todos"
                            ).json():
                if todo["userId"] == users["id"]:
                    dictionary = {}
                    dictionary["task"] = todo["title"]
                    dictionary["completed"] = todo["completed"]
                    dictionary["username"] = users["username"]
                    emptylist.append(dictionary)
        dump(final_dict, json_file)


if __name__ == "__main__":
    export_to_json()
