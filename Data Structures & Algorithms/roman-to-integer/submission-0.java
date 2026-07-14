class Solution {
    public int romanToInt(String s) {
        String[] car = s.split("");
        int gVal = 0;
        String previousChar = "Z";
        int out = 0;
        HashMap<String, Integer> tab = new HashMap<String, Integer>();
        tab.put("Z", 0);
        tab.put("I", 1);
        tab.put("V", 5);
        tab.put("X", 10);
        tab.put("L", 50);
        tab.put("C", 100);
        tab.put("D", 500);
        tab.put("M", 1000);
 
        for (int i = 0; i < s.length(); i++){
            if (car[i].equals(previousChar)){
                gVal += tab.get(car[i]);
            } else if (!car[i].equals(previousChar)) {
                if (tab.get(car[i]) > tab.get(previousChar)){
                    out -= gVal;
                } else {
                    out += gVal;
                }
                previousChar = car[i];
                gVal = tab.get(car[i]);
            }
        }
        out += gVal;
        return out;
    }
}
