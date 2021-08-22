#pragma once
#include "irendersystem.h"

class TextRender : public IRenderSystem {
  public:
  TextRender(std::istream& is, std::ostream& os) : input(is), output(os) {};
  ~TextRender() {};
  // IRenderSystem interface
  public:
  void Table() const override;
  void FaceDown() const override;
  void Space(size_t count) const override;
  std::string AskUserName() const override;

  private:
  std::istream& input;
  std::ostream& output;
};
