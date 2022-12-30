def compareMin(a, b):
    if (a <= b):
        return a
    return b


#finding index given an ASCII number
def FindIndex(array, c_ASCII):
    for i in range(len(array)):
        c = chr(c_ASCII)
        if (array[i] == c):
            return i
    return -1

#go Clockwise
def goClockWise(array,pointer,charIndex,charList):
    charASCII = ord(charList[charIndex])

    subArray = []
    for i in range(pointer, len(array)):
        subArray.append(array[i])

    for i in range(pointer):
        subArray.append(array[i])

    step = FindIndex(subArray, charASCII)
    return step

#go antiClockwise
def goAntiClockWise(array,pointer,charIndex,charList):
    charASCII = ord(charList[charIndex])

    subArray = []
    for i in range(len(array)):
        subArray.append(array[i])

    for i in range(pointer + 1):
        subArray.append(array[i])

    #reverse
    subArray1 = []
    for i in range(len(subArray) - 1, -1, -1):
        subArray1.append(subArray[i])
    
    step = FindIndex(subArray1, charASCII);
    return step

def main():
    #initialise alphabet list
    Clock = []

    for i in range(97, 123, 1):
        character = chr(i)
        Clock.append(character)

    
    #user input
    userInput = input()

    #creating array storing char from the user input
    inputSize = len(userInput)
    charList = list(userInput)

    #create pointer and charIndex
    pointer = 0
    charIndex = 0

    #result
    result = 0

    while (charIndex < inputSize):
    
        stepGoClockwise = goClockWise(Clock, pointer, charIndex, charList)
        stepGoAntiClockwise = goAntiClockWise(Clock, pointer, charIndex, charList)

        stepChoose = compareMin(stepGoClockwise, stepGoAntiClockwise)
        result += stepChoose

        charASCII = ord(charList[charIndex])
        pointer = FindIndex(Clock, charASCII)

        #update pointer and charIndex
        charIndex += 1
        

    print(result)

main()