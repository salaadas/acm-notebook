import java.util.Scanner;
// https://en.wikipedia.org/wiki/Toads_and_Frogs

public class ToadsAndFrogsSolver {
    public static final char TOAD = 'T', FROG = 'F', EMPTY = '-';

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Board position (using TF-)? ");
        String board = in.nextLine().trim().toUpperCase();
        System.out.print("Current player (T/F)? ");
        char currentPlayer = in.nextLine().trim().toUpperCase().charAt(0);
        System.out.println("Winner: " + getWinner(board.toCharArray(), currentPlayer));
        in.close();
    }

    public static char getWinner(char[] board, char currentPlayer) {
        // TODO - implement

        // Algorithm:
        // For each legal move for the current player,
        //   - if we call getWinner on the resulting game state (new board, other player)
        //     and find that this leads to a win for the current player,
        //     then return the current player.
        // Otherwise, failing to find a winning play (or any legal play), return the opponent player.
        int bl = board.length;
        int start, end1, end2, sign;
        char opponent, winner;
        if (currentPlayer == TOAD) {
            start = 0; end1 = bl - 1; end2 = bl - 2; sign = +1;
            opponent = FROG;
        } else {
            start = bl - 1; end1 = 0; end2 = 1; sign = -1;
            opponent = TOAD;
        }
        for (int i = start; i != end1; i+=sign*1) {
            if (board[i] == currentPlayer) {
                if (board[i + sign] == EMPTY) {
                    board[i + sign] = currentPlayer;
                    board[i] = EMPTY;
                    winner = getWinner(board, opponent);
                    board[i] = currentPlayer;
                    board[i + sign] = EMPTY;
                    if (winner == currentPlayer) return winner;
                } else if (i != end2 && board[i + sign] == opponent && board[i + sign*2] == EMPTY) {
                    board[i + sign*2] = currentPlayer;
                    board[i] = EMPTY;
                    winner = getWinner(board, opponent);
                    board[i]= currentPlayer;
                    board[i + sign*2] = EMPTY;
                    if (winner == currentPlayer) return winner;
                }
            }
        }
        return opponent;
    }
}
