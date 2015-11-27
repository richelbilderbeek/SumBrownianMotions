#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "sumbrownianmotionsmenudialog.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>

#include <boost/lexical_cast.hpp>

#include <QFile>

#include "sumbrownianmotionsmenudialog.h"
#include "fileio.h"
#include "testtimer.h"
#include "trace.h"
#pragma GCC diagnostic pop

ribi::SumBrownianMotionsMenuDialog::SumBrownianMotionsMenuDialog()
{
  #ifndef NDEBUG
  Test();
  #endif
}

int ribi::SumBrownianMotionsMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1 || argc > 4)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  return 0;
}

ribi::About ribi::SumBrownianMotionsMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "SumBrownianMotions",
    "simulation",
    "November 27th of 2015",
    "2015-2015",
    "http://www.richelbilderbeek.nl/SumBrownianMotions.htm",
    GetVersion(),
    GetVersionHistory()
  );
  a.AddLibrary("TestTimer version: " + TestTimer::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

std::string ribi::SumBrownianMotionsMenuDialog::GetVersion() const noexcept
{
  return "2.0";
}

std::vector<std::string> ribi::SumBrownianMotionsMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2015-05-08: Version 1.0: initial version",
    "2015-11-27: Version 2.0: moved to own GitHub",
  };
}

ribi::Help ribi::SumBrownianMotionsMenuDialog::GetHelp() const noexcept
{
  return ribi::Help(
    GetAbout().GetFileTitle(),
    GetAbout().GetFileDescription(),
    {
      //No additional options
    },
    {
    }
  );
}

#ifndef NDEBUG
void ribi::SumBrownianMotionsMenuDialog::Test() noexcept
{
  {
    static bool is_tested{false};
    if (is_tested) return;
    is_tested = true;
  }
  {
    fileio::FileIo();
  }
  const TestTimer test_timer(__func__,__FILE__,1.0);
}
#endif
