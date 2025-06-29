# Project Description

This code participated in **"KBTU Data Science Challenge 2025"** and won the **first** place.

The data set was provided by the organizers and is based on real academic analytics. All data is taken from **kaggle**.

*Author: Alexey V.*


# Task description

## Goal

The goal of this project is to build a regression model that can **predict students' final math scores** based on various characteristics, including:

* **Demographic data** (gender, education of parents, type of school).
* **Academic performance** (number of study hours, attendance, previous grades)
* **Extracurricular activities**

The task includes preprocessing functions, normalizing data, building a model using TensorFlow/Keras, training, evaluation, and creating a CSV file with predicted estimates.


## Columns

**student\_id** — unique identifier of each student

**gender** — 'Male' or 'Female'

**age** — student’s age

**study\_hours** — average daily study hours

**attendance\_rate** — class attendance rate in %

**previous\_scores** — previous academic performance

**parental\_education** — level of parents' education

**school\_type** — 'Public' or 'Private' school

**extracurricular** — level of participation in activities

**final\_math\_score** — actual target value (used only in training)


## Tasks

* Data loading and preprocessing
* Normalization of numerical characteristics
* Training a neural network regression model
* Performance assessment and visualization
* Predicting the test suite and exporting to CSV

# Table of Contents

### 1. Data download
### 2. Visualization and data analysis
### 3. Preparation and normalization of functions
### 4. Model building and training
### 5. Visual assessment of the model
### 6. Prediction based on test data and generation of the final response