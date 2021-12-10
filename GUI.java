package com.notebook;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;


public class GUI extends JFrame
{
    private final GameField fifteenGameLogic = new GameField(this);
    private JFrame window;
    private final GridLayout layout = new GridLayout(4, 4);
    private final JPanel panel = new JPanel();
    
    public GUI()
    {
        createWindow();
        createGrid();
        KeyStrokes();
        MouseClick();
        
        window.setVisible(true);
    }

    public void createWindow()
    {
        window = new JFrame("15");
        window.setSize(800, 600);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void createGrid()
    {
        panel.removeAll();
        panel.setLayout(layout);

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                JPanel square = new JPanel();
                JLabel number;
                if (i == 3 && j == 3)
                {
                    number = new JLabel("");
                }
                else
                {
                    number = new JLabel("" + fifteenGameLogic.numbers[i][j]);
                }

                number.setFont(new Font(null, Font.BOLD, 30));
                square.setLayout(new GridBagLayout());
                square.add(number);
                square.setBorder(BorderFactory.createLineBorder(Color.black));

                panel.add(square);
            }
        }

        window.add(panel);
        panel.setVisible(true);
    }

    public void next()
    {
        for(int i = 0; i < panel.getComponents().length; ++i)
        {
            JLabel label = (JLabel)((JPanel)panel.getComponent(i)).getComponent(0);

            if (fifteenGameLogic.numbers[i / 4][i % 4] == 0)
            {
                label.setText("");
                panel.getComponent(i).setBackground(Color.black);
                continue;
            }

            label.setText("" + fifteenGameLogic.numbers[i / 4][i % 4]);
            if (fifteenGameLogic.numbers[i / 4][i % 4] != (i + 1))
            {
                panel.getComponent(i).setBackground(Color.RED);
            }
            else
            {
                panel.getComponent(i).setBackground(Color.GREEN);
            }
        }
    }

    public void MouseClick()
    {
        panel.addMouseListener(new MouseAdapter()
        {
            @Override
            public void mouseClicked(MouseEvent e)
            {
                int column = e.getX() / (panel.getWidth() / 4);
                int row = e.getY() / (panel.getHeight() / 4);
                if (row != 0 && fifteenGameLogic.numbers[row - 1][column] == 0)
                {
                    fifteenGameLogic.numbers[row - 1][column] = fifteenGameLogic.numbers[row][column];
                    fifteenGameLogic.numbers[row][column] = 0;
                }

                if (row != 3 && fifteenGameLogic.numbers[row + 1][column] == 0)
                {
                    fifteenGameLogic.numbers[row + 1][column] = fifteenGameLogic.numbers[row][column];
                    fifteenGameLogic.numbers[row][column] = 0;
                }

                if (column != 0 && fifteenGameLogic.numbers[row][column - 1] == 0)
                {
                    fifteenGameLogic.numbers[row][column - 1] = fifteenGameLogic.numbers[row][column];
                    fifteenGameLogic.numbers[row][column] = 0;
                }

                if (column != 3 && fifteenGameLogic.numbers[row][column + 1] == 0)
                {
                    fifteenGameLogic.numbers[row][column + 1] = fifteenGameLogic.numbers[row][column];
                    fifteenGameLogic.numbers[row][column] = 0;
                }

                next();
            }
        });
    }
    
    public void KeyStrokes()
    {
        window.addKeyListener(new KeyAdapter()
        {
            @Override
            public void keyPressed(KeyEvent e)
            {
                int row = 0;
                int column = 0;

                for (int i = 0; i < 4; i++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (fifteenGameLogic.numbers[i][j] == 0)
                        {
                            row = i;
                            column = j;
                            break;
                        }
                    }
                }

                if (!e.isControlDown() && e.getKeyCode() == KeyEvent.VK_UP && row != 3)
                {
                    fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row + 1][column];
                    fifteenGameLogic.numbers[row + 1][column] = 0;
                }

                if (!e.isControlDown() && e.getKeyCode() == KeyEvent.VK_DOWN && row != 0)
                {
                    fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row - 1][column];
                    fifteenGameLogic.numbers[row - 1][column] = 0;
                }

                if (!e.isControlDown() && e.getKeyCode() == KeyEvent.VK_LEFT && column != 3)
                {
                    fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row][column + 1];
                    fifteenGameLogic.numbers[row][column + 1] = 0;
                }

                if (!e.isControlDown() && e.getKeyCode() == KeyEvent.VK_RIGHT && column != 0)
                {
                    fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row][column - 1];
                    fifteenGameLogic.numbers[row][column - 1] = 0;
                }


                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_UP && row != 3)
                {
                    while (row != 3)
                    {
                        fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row + 1][column];
                        fifteenGameLogic.numbers[row + 1][column] = 0;
                        row++;
                    }
                }

                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_DOWN && row != 0)
                {
                    while (row != 0)
                    {
                        fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row - 1][column];
                        fifteenGameLogic.numbers[row - 1][column] = 0;
                        row--;
                    }
                }

                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_LEFT && column != 3)
                {
                    while (column != 3)
                    {
                        fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row][column + 1];
                        fifteenGameLogic.numbers[row][column + 1] = 0;
                        column++;
                    }
                }

                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_RIGHT && column != 0)
                {
                    while (column != 0)
                    {
                        fifteenGameLogic.numbers[row][column] = fifteenGameLogic.numbers[row][column - 1];
                        fifteenGameLogic.numbers[row][column - 1] = 0;
                        column--;
                    }
                }

                next();
            }
        });
    }
}
