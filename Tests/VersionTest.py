import subprocess

testName = 'Version test'


def run_version_test():
    result = subprocess.run(['FileCoder', 'version'], stdout=subprocess.PIPE)

    if result.stdout.decode("UTF-8").find("FileCoder Version:") > -1:
        return True
    else:
        return False
