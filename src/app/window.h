#pragma once

#include "emu.h"
#include <QLabel>
#include <QMessageBox>
#include <QPointer>
#include <QPushButton>
#include <QTableWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QToolBar>
#include <QWidget>

// `Window` class which wraps around a `QWidget`
class Window : public QWidget
{
public:
  explicit Window(QWidget* parent = nullptr);

  // Helper method to setup/place tables on `Window`
  void setup_tables();

  // Helper method to setup/place toolbar on `Window`
  void setup_toolbar();

public slots:
  // Event-handler for when `shutdown_button` is clicked
  void shutdown_program(bool clicked);

  // Event-handler for when `load_rom_button` is clicked
  void load_rom_dialog(bool clicked);

  // Event-handler for when `execute_rom_button` is clicked
  void execute_rom(bool clicked);

  // Event-handler for when `execute_instr` is clicked
  void execute_instr(bool clicked);

  // Event-handler for when `reset_button` is clicked
  void reset_handler(bool clicked);

  // Event-handler for when `music_button` is clicked
  void music_handler(bool clicked);

  // Event-handler for when `about_button` is clicked
  void about_handler(bool clicked);

private:
  QPushButton* shutdown_button;
  QPushButton* execute_rom_button;
  QPushButton* execute_instr_button;
  QPushButton* load_rom_button;
  QPushButton* reset_button;
  QPushButton* music_button;
  QPushButton* about_button;

  QMediaPlayer* musicbox;
  QAudioOutput* audio;

  // To load roms or quit program
  QToolBar* toolbar;

  // Primary registers
  QTableWidget* register_table1;

  // Secondary Registers (used infrequently)
  QTableWidget* register_table2;

  // Special registers (like PC or SP)
  QTableWidget* register_table3;

  // All of the flags
  QTableWidget* flag_table;

  // Team 2 logo
  QLabel* team_logo_image;

  // Composition of the `emulator`
  CPUEmulator* emulator = nullptr;

  // Path to test rom
  QString file_path = nullptr;

  // is file loaded?
  bool file_loaded = false;

  // is music playing?
  bool music_playing = false;
};
