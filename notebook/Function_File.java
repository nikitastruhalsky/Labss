package com.notebook;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Function_File
{
    String fileName;
    String fileAddress;

    public Function_File()
    {
    }

    public void newFile(JTextPane textPane, JFrame window)
    {
        textPane.setText("");
        window.setTitle("New");
        fileName = null;
        fileAddress = null;
    }

    public void open(JFrame window, JTextPane textPane)
    {
        FileDialog fileDialog = new FileDialog(window, "Open", FileDialog.LOAD);
        fileDialog.setVisible(true);

        if (fileDialog.getFile() != null)
        {
            fileName = fileDialog.getFile();
            fileAddress = fileDialog.getDirectory();
            window.setTitle(fileName);
        }
        System.out.println("File address and file name " + fileAddress + fileName);

        try
        {
            BufferedReader bufferedReader = new BufferedReader(new FileReader(fileAddress + fileName));
            textPane.read(bufferedReader, null);
            bufferedReader.close();
        }
        catch (Exception e)
        {
            System.out.println("FILE NOT OPENED!");
        }
    }

    public void save(JTextPane textPane, JFrame window)
    {
        if (fileName == null)
        {
            saveAs(textPane, window);
        }
        else
        {
            try
            {
                FileWriter fileWriter = new FileWriter(fileAddress + fileName);
                fileWriter.write(textPane.getText());
                window.setTitle(fileName);
                fileWriter.close();
            }
            catch (Exception e)
            {
                System.out.println("SOMETHING WRONG!");
            }
        }
    }

    public void saveAs(JTextPane textPane, JFrame window)
    {
        FileDialog fileDialog = new FileDialog(window, "Save", FileDialog.SAVE);
        fileDialog.setVisible(true);

        if (fileDialog.getFile() != null)
        {
            fileName = fileDialog.getFile();
            fileAddress = fileDialog.getDirectory();
            window.setTitle(fileName);
        }

        try
        {
            FileWriter fileWriter = new FileWriter(fileAddress + fileName);
            fileWriter.write(textPane.getText());
            fileWriter.close();
        }
        catch (Exception e)
        {
            System.out.println("SOMETHING WRONG!");
        }
    }

    public void exit()
    {
        System.exit(0);
    }

    public void find(JTextPane textPane, JLabel label, JButton findButton, JButton nextButton, JTextField input)
    {
        JFrame jFrame = new JFrame("Find");
        jFrame.setLayout(new FlowLayout());
        jFrame.setSize(300, 120);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.add(label);
        jFrame.add(findButton);
        input.addFocusListener(new FocusAdapter()
        {
            public void focusGained(FocusEvent e)
            {
                JTextField source = (JTextField)e.getComponent();
                source.setText("");
                source.removeFocusListener(this);
            }
        });
        jFrame.add(input);
        jFrame.add(nextButton);
        nextButton.setVisible(false);
        jFrame.setVisible(true);

        final int[][] start = new int[1][1];
        final int[][] end = new int[1][1];
        final int[] count = new int[1];

        final int[] number = {0};

        findButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                start[0] = new int[1000];
                end[0] = new int[1000];
                count[0] = -1;
                Pattern pat = Pattern.compile(input.getText());
                Matcher mat = pat.matcher(textPane.getText());
                while(mat.find())
                {
                    ++count[0];
                    start[0][count[0]] = mat.start();
                    end[0][count[0]] = mat.end();
                }
                nextButton.setVisible(true);
                textPane.setSelectionStart(start[0][0]);
                textPane.setSelectionEnd(end[0][0]);
                number[0] = 0;
            }
        });


        nextButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                if (number[0] <= count[0])
                {
                    ++number[0];
                    textPane.setSelectionStart(start[0][number[0]]);
                    textPane.setSelectionEnd(end[0][number[0]]);
                }
                else
                {
                    textPane.setSelectionStart(start[0][0]);
                    textPane.setSelectionEnd(end[0][0]);
                    number[0] = 0;
                }
            }
        });
    }

    public void replace(JTextPane textPane, JLabel label, JButton replaceButton, JTextField inputOldFragment,
                        JTextField inputNewFragment)
    {
        JFrame jFrame = new JFrame("Replace");
        jFrame.setLayout(new FlowLayout());
        jFrame.setSize(300, 120);
        jFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        jFrame.add(label);
        jFrame.add(replaceButton);
        inputOldFragment.addFocusListener(new FocusAdapter()
        {
            public void focusGained(FocusEvent e)
            {
                JTextField source = (JTextField)e.getComponent();
                source.setText("");
                source.removeFocusListener(this);
            }
        });
        inputNewFragment.addFocusListener(new FocusAdapter()
        {
            public void focusGained(FocusEvent e)
            {
                JTextField source = (JTextField)e.getComponent();
                source.setText("");
                source.removeFocusListener(this);
            }
        });
        jFrame.add(inputOldFragment);
        jFrame.add(inputNewFragment);
        jFrame.setVisible(true);

        replaceButton.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                String str = textPane.getText();
                Pattern pat = Pattern.compile(inputOldFragment.getText());
                Matcher mat = pat.matcher(str);
                String new_fragment = inputNewFragment.getText();
                str = mat.replaceAll(new_fragment);
                textPane.setText(str);
            }
        });
    }
}
