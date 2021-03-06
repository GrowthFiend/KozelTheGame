#pragma once

#include <unordered_map>

#include "iuserinterface.hpp"

constexpr char32_t UNICODE_HEARTS = 0xB;
constexpr char32_t UNICODE_DIAMONDS = 0xC;
constexpr char32_t UNICODE_CROSSES = 0xD;
constexpr char32_t UNICODE_SPADES = 0xA;
constexpr char32_t UNICODE_DEFAULT = 0x0000;
constexpr char32_t UNICODE_6 = 0x6;
constexpr char32_t UNICODE_7 = 0x7;
constexpr char32_t UNICODE_8 = 0x8;
constexpr char32_t UNICODE_9 = 0x9;
constexpr char32_t UNICODE_J = 0xB;
constexpr char32_t UNICODE_Q = 0xD;
constexpr char32_t UNICODE_K = 0xE;
constexpr char32_t UNICODE_T = 0xA;
constexpr char32_t UNICODE_A = 0x1;
constexpr char32_t UTICODE_PREFIX = 0x1F000;
class TextUI : public IUserInterface {
public:
  TextUI(std::istream &is, std::ostream &os) : input(is), output(os){};
  TextUI(const TextUI &) = delete;
  TextUI &operator=(TextUI &) = delete;
  TextUI(const TextUI &&) = delete;
  TextUI &operator=(TextUI &&) = delete;
  ~TextUI() override = default;
  static const std::unordered_map<int, std::string> SuitToColor;
  // IRenderSystem interface

  void RenderTable(const Players &players, const Stake &stake, const Deck &deck,
                   int score_t1, int score_t2) const override;
  void RenderFaceDown() const override;
  void RenderSpace(size_t count) const override;
  void RenderWinner(int team) const override;
  void TrumpIs(const Card &card) const override;
  void NeverBeliveInAce() const override;
  [[nodiscard]] std::string AskUserName() const override;

private:
  std::istream &input;
  std::ostream &output;
};

std::u32string GenCardName(const Card &card);
std::ostream &operator<<(std::ostream &os, const Card &card);
