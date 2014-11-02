set term gif giant
set terminal gif 
set output "result.gif"
set title "convergence test" tc lt 1 
set xlabel "Ln N^1/3" tc lt 3
set ylabel "Ln ||U||" tc lt 3
set style line 1 lt 1 lw 10 pt 4 ps 5 
set key right top 
set size square
set xrange[1.5:5]
set yrange[-11:-7.5]
plot "plotting_data.dat"  ti "pGFEM" with linespoints linecolor 3 linewidth 2 pointtype 5 pointsize 2
