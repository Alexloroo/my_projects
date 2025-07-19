![](https://unsplash.com/photos/a-person-holding-a-business-card-in-front-of-a-computer-screen-onkUUiqTU0M)
# Project Description

This project predicts the **next day's closing stock price** of Microsoft using historical market data.

The data is based on daily OHLCV values and was processed using time series techniques and an LSTM neural network.

*Made by Alexey V.*



# Task Description

## Purpose

The objective of this project is to build a deep learning model that can **forecast the next day's closing price** of Microsoft stock, using both price-based features and technical indicators.


## Columns in Dataset

**Date** — date of each observation

**Open, High, Low, Close** — standard daily OHLC data

**Volume** — trading volume

Additional features created:

* **Range** = High - Low

* **Close\_Open\_Ratio** = Close / Open

* **SMA\_5**, **SMA\_10**, **SMA\_20** — simple moving averages of Close price



## Tasks

* Load and visualize historical price data
* Engineer features and technical indicators
* Scale and prepare the dataset
* Build an LSTM-based forecasting model
* Train and evaluate the model
* Predict the next day’s closing price



# Table of Contents

### 1. Data loading and visualization

### 2. Feature engineering

### 3. Data scaling and sequence generation

### 4. Model building with LSTM

### 5. Training and validation

### 6. Evaluation and plotting predictions

### 7. Forecasting the next day’s Close price