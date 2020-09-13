import subprocess

result = subprocess.run(['FileCoder', 'version'], stdout=subprocess.PIPE)

if result.stdout.decode("UTF-8").find("FileCoder Version:") > -1:
    print("OK")
else:
    print("Bad")
