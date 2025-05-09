#pragma once

#include <string>
#include <vector>

enum Suit {
  NoSuit,
  Club,
  Diamond,
  Heart,
  Spade,
};

enum Rank {
  NoRank,
  Two,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Eight,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

enum HandType {
  NoHandType,
  HighCard,
  OnePair,
  TwoPair,
  ThreeOfAKind,
  Straight,
  Flush,
  FullHouse,
  FourOfAKind,
  StraightFlush,
  RoyalFlush,
};

struct Card {
  Card() = default;
  Card(const std::string &);

  friend bool operator<(const Card &l, const Card &r) {
    if (l.rank < r.rank)
      return true;
    else if (l.rank == r.rank)
      return l.suit < r.suit;
    return false;
  }

  Rank rank{NoRank};
  Suit suit{NoSuit};
};

struct Hand {
  Hand() = default;
  Hand(std::vector<Card> &&cards);

  void add_card(Card &&);

  HandType type() const { return type_; }

private:
  void compute_hand_type();

  std::vector<Card> cards_{};
  HandType type_{NoHandType};
};
