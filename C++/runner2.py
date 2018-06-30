##go to directory with c++ code, call C:\python27\python runner2.py exec tests
##I.1 O.1

import sys, os, subprocess, time
if len(sys.argv) != 3:
    print "Usage: runner.py <executable> <test directory name>"
    sys.exit(1);
exec_name = sys.argv[1]
dir_name = sys.argv[2]
print "running executable %s on directory %s" %(exec_name, dir_name)

files = os.listdir(dir_name)
files.sort(key=lambda x:(int( (os.path.splitext(x)[1])[1:] ), os.path.splitext(x)[0]))
N = len(files)


for f_name in files:
    if os.path.splitext(f_name)[0] == 'I':
        full_name = os.path.join(dir_name, f_name)
        print "Test Case " + (os.path.splitext(f_name)[1])[1:]+":",
        fin = open(full_name, "r")
        fout = open("temp.out", "w")
        ferror = open("temp.err", "w")
        fcor = open(os.path.join(dir_name, "O"+os.path.splitext(full_name)[1]), "r");
        proc = subprocess.Popen(exec_name, stdin=fin, stdout=fout, stderr = ferror)
        #subprocess.call([exec_name], stdin=fin, stdout=fout)

        total = 2.0
        split = 50
        for i in range (split):
            time.sleep(total/split)
            if proc.poll() == 0:
                break;

        bad = False

        x = proc.poll()
        if x is None:
            proc.terminate()
            print "Time Limit Exceeded (or Runtime Error)"
            continue

        if x != 0:
            print "Exited with value", x
            continue

        fout.close();
        ferror.close()
        if (file("temp.err").read().strip() != ""):
            print "Runtime Error"
            continue

        cnt = 0
        for line in file("temp.out"):
            cnt+=1
            fline = fcor.readline()
            if line != fline:
                print "WA"
                #print "Your output: " + line.strip()+"\nExpected Output " + fline.strip()+"\n"
                bad = True
                break;
        #print cnt
        fline = fcor.read()
        if fline.strip() != "":
            print "WA, More output expected"
            print "Expected " + fline.strip()
            continue
        if (not bad):
            print "Correct"
