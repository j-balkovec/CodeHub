from setuptools import setup

setup(
    name='mock_testing_framework',
    version='1.0',
    description='Testing framework in Python',
    author='Jakob Balkovec',
    packages=['mock_testing_framework'],
    install_requires=[],
)

"""__summary
Shell:
```
python setup.py sdist bdist_wheel
```
Shell:
```
pip install .
```
Shell:
```
import Testing_framework/Python
```

"""
