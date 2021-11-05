1. compile encoder:
	g++ -I/home/pankaj/Documents/flatbtest/flatbuffers/include encoder.cpp 

2. generate file for person
        ./aout -p person.bin
        ./a.out -g group.bin

3. compile decoder
	g++ -I/home/pankaj/Documents/flatbtest/flatbuffers/include decoder.cpp 

4. decode:
	./a.out person.bin
	./a.out group.bin

5. To generate schema:
	flatc -cpp schema.fbs
