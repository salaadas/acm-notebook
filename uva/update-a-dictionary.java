import java.util.Scanner;
import java.util.Map;
import java.util.TreeMap;
// import java.util.StringBuilder;
import java.util.Set;

class Main {
    static Scanner in = new Scanner(System.in);
    public static void main(String[] args) {
        int t = Integer.parseInt(in.nextLine());
        // in.nextLine();
        while (t-- != 0) {
            Map<String, String> tm1 = new TreeMap<>();
            String line = in.nextLine();
            int s = 0;
            int ll = line.length();
            while (true) {
                int e = line.indexOf(':', s);
                e = e == -1 ? (ll - 1) : e;
                String key = line.substring(s + 1, e);
                s = e;
                if (e == ll - 1) break;

                e = line.indexOf(',', s);
                e = e == -1 ? (ll - 1) : e;
                String value = line.substring(s + 1, e);
                s = e;

                tm1.put(key, value);
                if (e == ll - 1) break;
            }

            line = in.nextLine();
            s = 0;
            ll = line.length();
            Map<String, String> tm2 = new TreeMap<>();
            while (true) {
                int e = line.indexOf(':', s);
                e = e == -1 ? (ll - 1) : e;
                String key = line.substring(s + 1, e);
                s = e;
                if (e == ll - 1) break;

                e = line.indexOf(',', s);
                e = e == -1 ? (ll - 1) : e;
                String value = line.substring(s + 1, e);
                s = e;

                tm2.put(key, value);
                if (e == ll - 1) break;
            }

            Set<String> tm1K = tm1.keySet();
            Set<String> tm2K = tm2.keySet();
            StringBuilder sb1 = new StringBuilder();
            sb1.append("+");
            StringBuilder sb2 = new StringBuilder();
            sb2.append("*");
            StringBuilder sb3 = new StringBuilder();
            sb3.append("-");
            for (String ss : tm2K) {
                if (!tm1K.contains(ss)) {
                    sb1.append(ss);
                    sb1.append(",");
                } else {
                    if (!tm2.get(ss).equals(tm1.get(ss))) {
                        sb2.append(ss);
                        sb2.append(",");
                    }
                }
            }
            for (String ss : tm1K) {
                if (!tm2K.contains(ss)) {
                    sb3.append(ss);
                    sb3.append(",");
                }
            }

            boolean tf = false;
            if (sb1.length() != 1) {
                System.out.println(sb1.toString().substring(0, sb1.length() - 1));
                tf = true;
            }
            if (sb3.length() != 1) {
                System.out.println(sb3.toString().substring(0, sb3.length() - 1));
                tf = true;
            }
            if (sb2.length() != 1) {
                System.out.println(sb2.toString().substring(0, sb2.length() - 1));
                tf = true;
            }
            if (tf == false) {
                System.out.println("No changes");
            }

            if (t != 0) System.out.println();
        }
    }
}
