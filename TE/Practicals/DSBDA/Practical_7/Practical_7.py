#!/usr/bin/env python
# coding: utf-8

import nltk
import string
import pandas as pd
import numpy as np

from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk import pos_tag
from nltk.stem import PorterStemmer, WordNetLemmatizer

from sklearn.feature_extraction.text import TfidfVectorizer

# (Run once if needed)
# nltk.download('punkt')
# nltk.download('stopwords')
# nltk.download('wordnet')
# nltk.download('averaged_perceptron_tagger')

# -------------------- PART A: TEXT PREPROCESSING --------------------

text = """Data Science is an interdisciplinary field that uses scientific methods,
processes, algorithms and systems to extract knowledge from structured and unstructured data."""

print(text)

# Sentence Tokenization
sentences = sent_tokenize(text)
print("Sentences:", sentences)

# Word Tokenization
words = word_tokenize(text)
print("Words:", words)

# Remove Punctuation
words_no_punct = [word for word in words if word.isalnum()]
print("Without Punctuation:", words_no_punct)

# Stopword Removal
stop_words = set(stopwords.words("english"))
filtered_words = [word for word in words_no_punct if word.lower() not in stop_words]
print("Filtered Words:", filtered_words)

# POS Tagging
pos_tags = pos_tag(filtered_words)
print("POS Tags:", pos_tags)

# Stemming
ps = PorterStemmer()
stemmed_words = [ps.stem(word) for word in filtered_words]
print("Stemmed Words:", stemmed_words)

# Lemmatization
lemmatizer = WordNetLemmatizer()
lemmatized_words = [lemmatizer.lemmatize(word) for word in filtered_words]
print("Lemmatized Words:", lemmatized_words)

# -------------------- PART B: TF-IDF --------------------

documents = [
    "Data Science is used for extracting knowledge.",
    "Machine learning is a part of Data Science.",
    "Big Data analytics helps in decision making."
]

vectorizer = TfidfVectorizer()
tfidf_matrix = vectorizer.fit_transform(documents)

print("Vocabulary:", vectorizer.get_feature_names_out())
print("TF-IDF Matrix:\n", tfidf_matrix.toarray())