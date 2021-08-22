#pragma once
#include <iostream>
#include <string>

class IRenderSystem {
  public:
  IRenderSystem() = default;
  virtual void Table() const;
  virtual void FaceDown() const;
  virtual void Space(size_t count) const;
  virtual std::string AskUserName() const;
  virtual ~IRenderSystem() {};
};
