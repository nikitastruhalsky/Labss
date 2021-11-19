package com.notebook;

import javax.swing.*;
import javax.swing.JScrollPane;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import java.awt.event.*;

public class GUI implements ActionListener
{
    JFrame window;
    JTextPane textPane;
    JScrollPane scrollPane;
    JMenuBar menuBar;
    JMenu fileMenu, menuFindAndReplace;
    JMenuItem iNew, iOpen, iSave, iSaveAs, iExit, iFind, iReplace;
    JButton findButton = new JButton("Find");
    JButton nextButton = new JButton("Next");
    JButton replaceButton = new JButton("Replace");
    JTextField input = new JTextField("Text to find", 7);
    JTextField inputOldFragment = new JTextField("Old fragment", 8);
    JTextField inputNewFragment = new JTextField("New fragment", 8);
    JLabel label = new JLabel();
    Function_File file = new Function_File();

    public GUI()
    {
        createWindow();
        createTextPane();
        createMenuBar();
        createFileMenu();
        createMenuFindAndReplace();

        window.setVisible(true);
    }

    public void createWindow()
    {
        window = new JFrame("Notepad");
        window.setSize(800, 600);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void createTextPane()
    {
        textPane = new JTextPane();

        scrollPane = new JScrollPane(textPane, JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setBorder(BorderFactory.createEmptyBorder());
        window.add(scrollPane);
    }

    public void createMenuBar()
    {
        menuBar = new JMenuBar();
        window.setJMenuBar(menuBar);

        fileMenu = new JMenu("File");
        menuBar.add(fileMenu);

        menuFindAndReplace = new JMenu("Find and replace");
        menuBar.add(menuFindAndReplace);
    }

    public void createFileMenu()
    {
        iNew = new JMenuItem("New");
        iNew.addActionListener(this);
        iNew.setActionCommand("New");
        fileMenu.add(iNew);

        iOpen = new JMenuItem("Open");
        iOpen.addActionListener(this);
        iOpen.setActionCommand("Open");
        fileMenu.add(iOpen);

        iSave = new JMenuItem("Save");
        iSave.addActionListener(this);
        iSave.setActionCommand("Save");
        fileMenu.add(iSave);

        iSaveAs = new JMenuItem("Save As");
        iSaveAs.addActionListener(this);
        iSaveAs.setActionCommand("SaveAs");
        fileMenu.add(iSaveAs);

        iExit = new JMenuItem("Exit");
        iExit.addActionListener(this);
        iExit.setActionCommand("Exit");
        fileMenu.add(iExit);
    }

    public void createMenuFindAndReplace()
    {
        iFind = new JMenuItem("Find");
        iFind.addActionListener(this);
        iFind.setActionCommand("Find");
        menuFindAndReplace.add(iFind);

        iReplace = new JMenuItem("Replace");
        iReplace.addActionListener(this);
        iReplace.setActionCommand("Replace");
        menuFindAndReplace.add(iReplace);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        String command = e.getActionCommand();

        switch (command)
        {
            case "New":
            {
                file.newFile(this.textPane, this.window);
                break;
            }

            case "Open":
            {
                file.open(this.window, this.textPane);
                break;
            }

            case "SaveAs":
            {
                file.saveAs(this.textPane, this.window);
                break;
            }

            case "Save":
            {
                file.save(this.textPane, this.window);
                break;
            }

            case "Exit":
            {
                file.exit();
                break;
            }

            case "Find":
            {
                file.find(this.textPane, this.label, this.findButton, this.nextButton, this.input);
                break;
            }

            case "Replace":
            {
                file.replace(this.textPane, this.label, this.replaceButton, this.inputOldFragment, this.inputNewFragment);
            }
        }
    }
}
