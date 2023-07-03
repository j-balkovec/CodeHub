# Sentiment Analysis Algorithm

## Description

This sentiment analysis algorithm is written in Python and utilizes the Natural Language Toolkit (NLTK) library to classify textual data based on sentiment polarity. It reads data from a .csv file, performs sentiment analysis on the text, and classifies it as positive, negative, or neutral.

## Dependencies

To run this algorithm, make sure you have the following dependencies installed:

- Python (version 3.6 or above)
- NLTK (Natural Language Toolkit) library

```shell
pip install nltk
pip install json
pip install tqdm
```

### Project Structure

- `extremes.py`: Finds the tweets with extreme polarity (+ and -)
- `main.py`: Main file that executes the algorithm

### Usage

To use the SAA, follow these steps:

1. Clone or fork the repository or navigate to the "Projects" directory on your local machine.

2. Prepare your data:
  - Ensure your data is in a .csv file format
  - The `.csv` file should have a column containing the text data to be analyzed.

3. Install dependencies and run with `python main.py` or `python3 main.py` in the terminal

### Conda

If you're using Conda, run the following:

```shell
conda activate name_of_your_env
python main.py
python3 main.py
```

### Mock Data
GitHub prohibits the upload of files greater than 25MB. The original dataset can be found [here](https://brightdata.com/products/datasets/Twitter?kw=&cpn=13950045001&utm_matchtype=&utm_matchtype=&cq_src=google_ads&cq_cmp=13950045001&cq_term=&cq_plac=&cq_net=g&cq_plt=gp&utm_term=&utm_campaign=datasets-c1-search_generic-kw_en-desktop&utm_source=adwords&utm_medium=ppc&utm_content=dataset-dsa&hsa_acc=1393175403&hsa_cam=13950045001&hsa_grp=133051793747&hsa_ad=622510825430&hsa_src=g&hsa_tgt=dsa-532722321722&hsa_kw=&hsa_mt=&hsa_net=adwords&hsa_ver=3&gclid=CjwKCAjw44mlBhAQEiwAqP3eVurbFkqu723FK31ZH0DbS9CyjSjy3Pg_BXbENPoi6tMsdFPWuZyw1hoClHEQAvD_BwE)

`mock_s.csv` contains 1000 lines of data
`mock_m.csv` contains 10000 lines of data
`mock_l.csv` contains 100000 lines of data

`twitter_data.csv` contains 160 million lines of data

### Contributing

Contributions to the Projects directory are welcome! If you have any improvements, additional projects, or bug fixes to suggest, feel free to submit a pull request. Please follow the contribution guidelines and code of conduct outlined in the repository.

###  License

This project is NOT licensed under the [MIT License](https://theuselessweb.com). You are free to use, modify, and distribute the code and projects within this directory.



