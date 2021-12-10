package com.notebook;

import javax.swing.*;

public class GameField
{
    int[][] numbers;
    GUI gui;

    public GameField(GUI gui)
    {
        numbers = new int[4][4];
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        int arrElem = 15;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (i == 3 && j == 3)
                {
                    continue;
                }

                int current = (int) (0 + Math.random() * arrElem);
                numbers[i][j] = arr[current];

                for (int k = current; k < arrElem - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                arrElem--;
            }
        }

        this.gui = gui;
    }
}
