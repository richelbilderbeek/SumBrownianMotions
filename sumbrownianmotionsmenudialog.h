#ifndef SUMBROWNIANMOTIONMENUDIALOG_H
#define SUMBROWNIANMOTIONMENUDIALOG_H

#include "menudialog.h"

namespace ribi {

struct SumBrownianMotionsMenuDialog final : public MenuDialog
{
  SumBrownianMotionsMenuDialog();
  ~SumBrownianMotionsMenuDialog() noexcept {}
  int ExecuteSpecific(const std::vector<std::string>& argv) noexcept override;

  About GetAbout() const noexcept override;
  Help GetHelp() const noexcept override;
  std::string GetVersion() const noexcept override;
  std::vector<std::string> GetVersionHistory() const noexcept override;

  private:

  #ifndef NDEBUG
  static void Test() noexcept;
  #endif
};

} //~namespace ribi

#endif // SUMBROWNIANMOTIONMENUDIALOG_H
