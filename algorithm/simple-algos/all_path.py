#filling the gap between edge1Index and edge2Index
def gap_closure( edge1Index, edge2Index, gapLen, gapStd):
    global gapIndex
    global K

    print 'enter filling gap...' + str(edge1Index) + '\t' + str(edge2Index)

    leftEdge = new_contig_set[edge1Index]
    rightEdge = new_contig_set[edge2Index]
    #gapStd = 10

    print 'gapLen = ' + str(gapLen) + '\tgapStd = ' + str(gapStd)

    extendNode = leftEdge[ len(leftEdge)-(K-1) : len(leftEdge) ]

    gapLenLimitMin = gapLen-gapStd
    gapLenLimitMax = gapLen+gapStd

    if gapLenLimitMax <= 0:
        #print 'the estimation maxmimum is less than 0...'
        return 0

    gapSet = []
    currentGapChoice = []
    currentGapChoice.append(edge1Index)
    gapSet.append((currentGapChoice,0))

    out_gap = open(outPrefix + 'gap_' + str(edge1Index) + '_' + str(edge2Index),'w')
    out_gap.write(str(posList[edge1Index]) + '\t' + str(posList[edge2Index]) + '\n')
    out_gap.write('gapLenLimitMin = ' + str(gapLenLimitMin) + '\t' + 'gapLenLimitMax = ' + str(gapLenLimitMax) + '\n')

    finalGapSet = []
    #iteStep = 0

    while 1:
        #iteStep += 1
        #if iteStep > 100:
          #  break
        gapSet2 = []
        for currentGapPair in gapSet:
            (currentGapChoice,dis) = currentGapPair
            if dis < gapLenLimitMax:
                extendContig = new_contig_set[currentGapChoice[len(currentGapChoice)-1]]
                extendNode = extendContig[len(extendContig)-(K-1):len(extendContig)]
                if extendNode in leftBranchNodeList:
                    currentGapChoice.append(0)
                    for childNode in leftBranchNodeList[extendNode]:
                        currentLen = dis + int(len(new_contig_set[childNode]) - K + 1)
                        currentGapChoice[len(currentGapChoice)-1] = childNode
                        tempCurrentGapChoice = []
                        tempCurrentGapChoice = copy.deepcopy(currentGapChoice)
                        if childNode == edge2Index and dis <= gapLenLimitMax and dis >= gapLenLimitMin:
                            finalGapSet.append((tempCurrentGapChoice,dis))
                        gapSet2.append((tempCurrentGapChoice,currentLen))

        if int(len(gapSet2)) == 0:# or iteStep > 100:
            break
        gapSet = copy.deepcopy(gapSet2)

    if int(len(finalGapSet)) == 0:# or iteStep > 100:
        return 0


    if int( len( finalGapSet ) == 1 ):
        pair2 = (edge1Index,edge2Index)
        Cyto_uniq_gap_info.write(str(edge1Index) + '|' + str(len(new_contig_set[edge1Index])) + '|' + str(posList[edge1Index]) + '\t' + str(edge2Index) +'|' + str(len(new_contig_set[edge2Index])) + '|' + str(posList[edge2Index]) + '\t' +  str(int(gapLen)) + '|' + str(gapIndex)  + '\t' + 'b' + '\n' )

        pairExist = []
        (gap_candidate,disL) = finalGapSet[0]
        print str(len(gap_candidate))
        fout_uniq_gap_info.write('>gap\t' + str(gapIndex) + '\n')

        for j in range( len(gap_candidate) - 1):
            fout_uniq_gap_info.write('%5d\t%5d\t%s\n' %( gap_candidate[j] , len( new_contig_set[gap_candidate[j]]) , str(posList[gap_candidate[j]])))
            contig_i = gap_candidate[j]
            contig_j = gap_candidate[j+1]
            pairInGap = (contig_i , contig_j)
            print str(pairInGap)
            if pairInGap in pairExist:
                print str(pairInGap)
                continue
            pairExist.append(pairInGap)
            Cyto_uniq_gap_info.write(str(contig_i) + '|' + str(len(new_contig_set[contig_i])) + '|' + str(posList[contig_i]) + '\t' + str(contig_j) +'|' + str(len(new_contig_set[contig_j])) + '|' + str(posList[contig_j]) + '\t' +  str(0) + '|' + str(gapIndex) + '\t' + 'g' + str(gapIndex) + '\n' )
        gapIndex += 1

    if int( len( finalGapSet ) > 1 ):
        pair2 = (edge1Index,edge2Index)
        out = open(outPrefix + 'Cyto_gap_' + str(edge1Index) + '_' + str(edge2Index),'w')
        Cyto_multi_gap_info.write(str(edge1Index) + '|' + str(len(new_contig_set[edge1Index])) + '|' + str(posList[edge1Index]) + '\t' + str(edge2Index) +'|' + str(len(new_contig_set[edge2Index])) + '|' + str(posList[edge2Index]) + '\t' +  str(int(gapLen)) + '|' + str(gapIndex)  + '\t' + 'b' + '\n' )
        out.write(str(edge1Index) + '|' + str(len(new_contig_set[edge1Index])) + '|' + str(posList[edge1Index]) + '\t' + str(edge2Index) +'|' + str(len(new_contig_set[edge2Index])) + '|' + str(posList[edge2Index]) + '\t' +  str(int(gapLen)) + '|' + str(gapIndex)  + '\t' + 'b' + '\n' )

        fout_multi_gap_info.write('>gap\t' + str(gapIndex) + '\n')
        pairExist = []

        for gap_i in range( len( finalGapSet ) ):
            fout_multi_gap_info.write('candidate\t' + str(gap_i) + '\n')
            (gap_candidate,disL) = finalGapSet[gap_i]
            print str(len(gap_candidate))
            for j in range( len(gap_candidate) - 1):
                fout_multi_gap_info.write('%5d\t%5d\t%s\n' %( gap_candidate[j] , len( new_contig_set[gap_candidate[j]]) , str(posList[gap_candidate[j]] )))
                contig_i = gap_candidate[j]
                contig_j = gap_candidate[j+1]
                pairInGap = (contig_i , contig_j)
                print str(pairInGap)
                if pairInGap in pairExist:
                    print str(pairInGap)
                    continue
                pairExist.append(pairInGap)
                Cyto_multi_gap_info.write(str(contig_i) + '|' + str(len(new_contig_set[contig_i])) + '|' + str(posList[contig_i]) + '\t' + str(contig_j) +'|' + str(len(new_contig_set[contig_j])) + '|' + str(posList[contig_j]) + '\t' +  str(0) + '|' + str(gapIndex) + '\t' + 'g' + str(gapIndex) + '\n' )
        gapIndex += 1
        out.close()


    out_gap_path_number.write('%5d\t%5d\t%5d\t%5d\t%5d\t%5s\t%5d\n' %(edge1Index,edge2Index,gapLen,gapStd,len(finalGapSet),'long',K))

    out_gap.write('Final gapSet\n')
    for i in range(len(finalGapSet)):
        out_gap.write(str(i) + '-th gap\n' + str(finalGapSet[i]) + '\n')
        (path,dis) = finalGapSet[i]
        for j in range(len(path)):
            out_gap.write('%5d\t%5d\t%s\n' %( path[j] , len( new_contig_set[path[j]]) , str(posList[path[j]])))

    out_gap.close()	
    return 1


