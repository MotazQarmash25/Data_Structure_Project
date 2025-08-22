# Data Structure Project – Path Loss Calculation  

## 📖 Project Overview  
This project implements a **C++ solution** for calculating **Signal Path Loss (PL)** in small/medium-sized cities using the **Okumura-Hata model**.  
It was developed as part of **Data Structures and Algorithms (10636211)** coursework at An-Najah National University.  

The program reads input values (Carrier Frequency, Distance, Base Station Height, Mobile Station Height) from a file, calculates the **Path Loss in dB**, validates frequency ranges, and writes the results to an output file in a formatted table with summary statistics.  

---

## 🧮 Formula Used  
Path Loss (PL) is calculated as:  

\[
PL = A + C \cdot \log_{10}(Distance)
\]

Where:  

- \( A = 69.55 + 26.16 \cdot \log_{10}(Carrier\_Frequency) - 13.82 \cdot \log_{10}(Base\_Station\_Height) - B \)  
- \( B = [1.1 \cdot \log_{10}(Carrier\_Frequency) - 0.7] \cdot Mobile\_Station\_Height - 1.56 \cdot \log_{10}(Carrier\_Frequency) + 0.8 \)  
- \( C = 44.9 - 6.55 \cdot \log_{10}(Base\_Station\_Height) \)  

**Valid range:** Carrier Frequency must be between **150 MHz and 1500 MHz**.  

---

## 📂 Input File Format  
- First line: number of readings (N).  
- Next N lines: four values → Carrier_Frequency (MHz), Distance (Km), Base_Station_Height (m), Mobile_Station_Height (m).  

Example:  
```
5
900 1 30 2
1000 10.5 100 3
300 5 70 10
2000 11 60 2
1450 5 10 9
```

---

## 🖥️ Output File Format  
- Table with input values + calculated Path Loss.  
- If Carrier Frequency is invalid → "Not Valid".  
- Summary including **average, maximum, and minimum** PL values.  

Example output:  
```
Carrier_Frequency   Distance   Base_Station_Height   Mobile_Station_Height   Path Loss
900                 1         30                    2                       125.1285
2000                11        60                    2                       NotValid
...

Summary:
Average PL = 205.6625 dB
Max PL = 146.4640 dB
Min PL = 114.6046 dB
```

---

## ⚙️ How to Compile & Run  
1. Save your code in `main.cpp`.  
2. Compile using g++:  
   ```bash
   g++ main.cpp -o pathloss
   ```  
3. Run the program:  
   ```bash
   ./pathloss
   ```  
4. Enter the **input file name** and the **output file name** when prompted.  

---

## 📘 Reference  
- [Okumura-Hata Model Basics](http://www.rfwireless-world.com/Terminology/Okumura-Hata-Model-basics.html)  
