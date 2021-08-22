
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0A6", 18, 0, ESuit::SHAMA}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0A7", 1, 0, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0A8", 2, 0, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0A9", 3, 0, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0AB", 4, 2, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0AD", 5, 3, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0AE", 6, 4, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0AA", 7, 10, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0A1", 8, 11, ESuit::SPADES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0B6", 0, 0, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0B7", 1, 0, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0B8", 2, 0, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0B9", 3, 0, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0BB", 4, 2, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0BD", 5, 3, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0BE", 6, 4, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0BA", 7, 10, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0B1", 8, 11, ESuit::HEARTS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0C6", 0, 0, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0C7", 1, 0, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0C8", 2, 0, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0C9", 3, 0, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0CB", 4, 2, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0CD", 5, 3, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0CE", 6, 4, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0CA", 7, 10, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0C1", 8, 11, ESuit::DIAMONDS}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0D6", 0, 0, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0D7", 1, 0, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0D8", 2, 0, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0D9", 3, 0, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0DB", 4, 2, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0DD", 5, 3, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0DE", 6, 4, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0DA", 7, 10, ESuit::CROSSES}));
//cards.push_back(std::make_unique<Card>(Card {U"\x1F0D1", 8, 11, ESuit::CROSSES}));

//void PrintCards(std::ostream& os) const;
//void PrintCard(std::ostream& os, size_t pos) const;

//void Deck::PrintCards(std::ostream& os) const {
//  if (!cards.size()) {
//    os << "no cards";
//    return;
//  }
//  for (auto& p : cards) { os << *p; }
//  os << std::endl;
//}

//void Deck::PrintCard(std::ostream& os, size_t pos) const {
//  if (!cards.size()) {
//    os << "no cards";
//    return;
//  }
//  os << *cards[pos] << std::endl;
//}
