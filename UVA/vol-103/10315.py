##  >>~~ UVa Online Judge ACM Problem Solution ~~<<

##  ID: 10315
##  Name: Poker Hands
##  Problem: https://onlinejudge.org/external/103/10315.pdf
##  Language: Python

##  Author: Arash Shakery
##  Email: arash.shakery@gmail.com

from sys import stdin, stdout
from collections import Counter

cards = stdin.read().split()

values_order = "23456789TJQKA"
def reval_cards(cards):
  return list(map(lambda c: (values_order.index(c[0])+1, c[1]), cards))

def sort_values(cards):
  cards.sort()
  return cards

def sort_suits(cards):
  cards.sort(key=lambda c: c[::-1])
  return cards


def is_straight_flush(cards):
  if is_flush(cards)>=0 and is_straight(cards)>=0:
     return cards[4][0]
  return -1

def is_four_of_a_kind(cards):
  if cards[0][0] == cards[3][0] or cards[1][0] == cards[4][0]:
    return cards[3][0]
  return -1

def is_full_house(cards):
  if cards[0][0] == cards[2][0] and cards[3][0] == cards[4][0]:
    return cards[0][0]
  if cards[0][0] == cards[1][0] and cards[2][0] == cards[4][0]:
     return cards[4][0]
  return -1

def is_flush(cards):
  if all(card[1] == cards[0][1] for card in cards[1:]):
    return cards[4][0]
  return -1

def is_straight(cards):
  if all(card[0] == cards[i-1][0]+1 for i,card in list(enumerate(cards))[1:]):
     return cards[4][0]
  return -1

def is_three_of_a_kind(cards):
  if cards[0][0] == cards[2][0]:
    return cards[0][0]
  if cards[2][0] == cards[4][0]:
    return cards[4][0]
  return -1

def is_pair(cards):
  c = Counter(map(lambda x: x[0], cards))
  pairs = list(filter(lambda x: x[1]==2, c.items()))
  pairs.sort(key=lambda x: -(x[1]*100 + x[0]))
  pairCards = list(map(lambda x: x[0], pairs+cards[::-1]))
  return sum(card*(15**(len(pairCards)-i)) for i,card in enumerate(pairCards))

value_funcs = [
  is_straight_flush,
  is_four_of_a_kind,
  is_full_house,
  is_flush,
  is_straight,
  is_three_of_a_kind
]

def poker_value(cards):
  for i, fn in enumerate(value_funcs):
    val = fn(cards)
    if val > -1:
      return -i, val, is_pair(cards)
  return -6, 0, is_pair(cards)

for i in range(0, len(cards), 10):
  black = sort_values(reval_cards(cards[i:i+5]))
  white = sort_values(reval_cards(cards[i+5:i+10]))
  v1 = poker_value(black)
  v2 = poker_value(white)

  if v1 > v2: print('Black wins.')
  elif v1 < v2: print('White wins.')
  else: print('Tie.')

