import settings


def print_result(test_name, status: bool):

    test_name = test_name.upper()

    if status:
        print(test_name + ':\t', settings.ok)
    else:
        print(test_name + ':\t', settings.bad)
