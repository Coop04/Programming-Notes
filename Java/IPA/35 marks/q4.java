/*
Create an "ElectricBoardManager" class to manage electric boards in a city. Each electric board is identified by its unique ID and keeps track of power consumption readings over a certain period.

Implement the class with the following two methods:

1. addReading(String boardId, List<Integer> readings)
   - This method accepts the board ID and a list of power consumption readings.
   - If the board ID already exists, append the new readings to the existing readings.
     Example:
     Existing:
     AI -> [100, 150]
     addReading("AI", [200, 250])
     Result:
     AI -> [100, 150, 200, 250]
   - If the board ID does not exist, create a new entry with the provided readings.
     Example:
     addReading("B2", [300, 350])
     Result:
     B2 -> [300, 350]

2. getAveragePowerConsumption(String boardId, int startingRange, int endingRange)
   - This method takes the board ID, startingRange, and endingRange as input.
   - Return the average power consumption for that board considering only the readings whose values lie between startingRange and endingRange (inclusive).
   - If the board ID does not exist or no readings fall within the specified range, return 0.0.

You need to write the code for the ElectricBoardManager class implementing the above functionalities. The class should be capable of managing multiple electric boards, and addReading() may be called multiple times for different boards.

You may create two classes:

1. ElectricBoardManager
   - Represents an individual electric board with its unique ID and power consumption readings.
   - Provides methods to add power readings and retrieve the average power consumption for a specified range.
   - (Note: boardId is of type String.)

2. Solution
   - Used to interact with the user and demonstrate the functionalities of ElectricBoardManager.
   - It prompts the user to enter:
     • Number of electric boards.
     • Board IDs.
     • Power consumption readings.
     • Board ID, startingRange, and endingRange for calculating the average.
   - It then calls the appropriate methods and prints the result.

Input Format:
1. Enter the number of electric boards.
2. For each electric board:
   - Enter the board ID.
   - Enter the number of power consumption readings.
   - Enter the readings.
3. Enter:
   - Board ID for which the average is to be calculated.
   - startingRange.
   - endingRange.

Sample Input 1:
1
B1
3
100
150
200
B1
100
200

Output 1:
Average power consumption for board B1 from 100 to 200:
150.0

Sample Input 2:
1
B1
3
100
150
200
B2
100
200

Output 2:
Average power consumption for board B2 from 100 to 200:
0.0

Sample Input 3:
2
B1
3
100
150
200
B2
2
50
75
B2
45
65

Output 3:
Average power consumption for board B2 from 45 to 65:
50.0
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class ElectricBoardManager {
    // unique boardId & power consumption readings
    private Map<String, List<Integer>> boardReadingsMap;

    public ElectricBoardManager() {
        boardReadingsMap = new HashMap<>();
    }

    // 1. addReading method
    public void addReading(String boardId, List<Integer> readings) {
        if (boardReadingsMap.containsKey(boardId)) {
            // board exists - append new readings to existing ones
            boardReadingsMap.get(boardId).addAll(readings);
        } else {
            // board does not exist - create new entry
            boardReadingsMap.put(boardId, new ArrayList<>(readings));
        }
    }

    // 2. getAveragePowerConsumption method
    public double getAveragePowerConsumption(String boardId, int startingRange, int endingRange) {
        if (!boardReadingsMap.containsKey(boardId)) {
            return 0.0;
        }

        List<Integer> readings = boardReadingsMap.get(boardId);
        double sum = 0;
        int count = 0;

        for (int reading : readings) {
            if (reading >= startingRange && reading <= endingRange) {
                sum += reading;
                count++;
            }
        }

        if (count == 0) {
            return 0.0;
        }

        return sum / count;
    }
}

public class q4 {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        ElectricBoardManager manager = new ElectricBoardManager();

        int numBoards = Integer.parseInt(sc.nextLine().trim());

        for (int i = 0; i < numBoards; i++) {
            String boardId = sc.nextLine().trim();
            int numReadings = Integer.parseInt(sc.nextLine().trim());

            List<Integer> readings = new ArrayList<>();
            for (int j = 0; j < numReadings; j++) {
                int reading = Integer.parseInt(sc.nextLine().trim());
                readings.add(reading);
            }

            manager.addReading(boardId, readings);
        }

        String queryBoardId = sc.nextLine().trim();
        int startingRange = Integer.parseInt(sc.nextLine().trim());
        int endingRange = Integer.parseInt(sc.nextLine().trim());

        double average = manager.getAveragePowerConsumption(queryBoardId, startingRange, endingRange);

        System.out.println("Average Power Consumption for board " + queryBoardId + ": " + average);
    }
}