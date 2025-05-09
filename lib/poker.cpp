#include "poker.hpp"

#include <cassert>
#include <map>
#include <stdexcept>

Card::Card(const std::string &s) {
  // Rank
  switch (s[0]) {
  case '2':
    rank = Two;
    break;
  case '3':
    rank = Three;
    break;
  case '4':
    rank = Four;
    break;
  case '5':
    rank = Five;
    break;
  case '6':
    rank = Six;
    break;
  case '7':
    rank = Seven;
    break;
  case '8':
    rank = Eight;
    break;
  case '9':
    rank = Nine;
    break;
  case 'T':
    rank = Ten;
    break;
  case 'J':
    rank = Jack;
    break;
  case 'Q':
    rank = Queen;
    break;
  case 'K':
    rank = King;
    break;
  case 'A':
    rank = Ace;
    break;
  default:
    throw std::invalid_argument(s);
  }

  // Suit
  switch (s[1]) {
  case 'C':
    suit = Club;
    break;
  case 'D':
    suit = Diamond;
    break;
  case 'H':
    suit = Heart;
    break;
  case 'S':
    suit = Spade;
    break;
  default:
    throw std::invalid_argument(s);
  }

  assert(suit != NoSuit);
  assert(rank != NoRank);
}

Hand::Hand(std::vector<Card> &&cards) : cards_{cards} { compute_hand_type(); }

void Hand::add_card(Card &&card) {
  if (cards_.size() == 5)
    throw std::range_error("Hand already has 5 cards");
  cards_.emplace_back(card);
}

bool is_straight(const std::vector<Card> &cards) {
  for (size_t i = 1; i < 5; i++)
    if (cards[i - 1].rank == Ace && i == 1 && cards[i].rank != Two)
      return false;
    else if (cards[i].rank != cards[i - 1].rank + 1)
      return false;
  return true;
}

void Hand::compute_hand_type() {
  std::map<Rank, unsigned> rank_freq;
  std::map<Suit, unsigned> suit_freq;
  for (const Card &c : cards_) {
    if (++rank_freq[c.rank] == 4) {
      type_ = FourOfAKind;
      return;
    }
    if (++suit_freq[c.suit] == 5)
      type_ = Flush;
  }

  // Check for straights
  if (is_straight(cards_)) {
    if (type_ == Flush) {
      if (cards_.back().rank == Ace)
        type_ = RoyalFlush;
      else
        type_ = StraightFlush;
    } else
      type_ = Straight;
  }
}
