#include "PolarCode.h"
#include <cmath>
#include <limits> 
#include <cmath>
#include <algorithm>
#include <string>

std::vector<int> ReliabilitySequence {0, 1, 2, 4, 8, 16, 32, 3, 5, 64, 9, 6, 17, 10, 18, 128, 12, 33, 65, 20, 256, 34, 24, 36, 7, 129, 66, 512, 11, 40, 68, 130, 19, 13, 48, 14, 72, 257, 21, 132, 35, 258, 26, 513, 80, 37, 25, 22, 
136, 260, 264, 38, 514, 96, 67, 41, 144, 28, 69, 42, 516, 49, 74, 272, 160, 520, 288, 528, 192, 544, 70, 44, 131, 81, 50, 73, 15, 320, 133, 52, 23, 134, 384, 76, 137, 82, 56, 27, 97, 
39, 259, 84, 138, 145, 261, 29, 43, 98, 515, 88, 140, 30, 146, 71, 262, 265, 161, 576, 45, 100, 640, 51, 148, 46, 75, 266, 273, 517, 104, 162, 53, 193, 152, 77, 164, 768, 268, 
274, 518, 54, 83, 57, 521, 112, 135, 78, 289, 194, 85, 276, 522, 58, 168, 139, 99, 86, 60, 280, 89, 290, 529, 524, 196, 141, 101, 147, 176, 142, 530, 321, 31, 200, 90, 545, 292, 
322, 532, 263, 149, 102, 105, 304, 296, 163, 92, 47, 267, 385, 546, 324, 208, 386, 150, 153, 165, 106, 55, 328, 536, 577, 548, 113, 154, 79, 269, 108, 578, 224, 166, 519, 552, 
195, 270, 641, 523, 275, 580, 291, 59, 169, 560, 114, 277, 156, 87, 197, 116, 170, 61, 531, 525, 642, 281, 278, 526, 177, 293, 388, 91, 584, 769, 198, 172, 120, 201, 336, 62, 
282, 143, 103, 178, 294, 93, 644, 202, 592, 323, 392, 297, 770, 107, 180, 151, 209, 284, 648, 94, 204, 298, 400, 608, 352, 325, 533, 155, 210, 305, 547, 300, 109, 184, 534, 
537, 115, 167, 225, 326, 306, 772, 157, 656, 329, 110, 117, 212, 171, 776, 330, 226, 549, 538, 387, 308, 216, 416, 271, 279, 158, 337, 550, 672, 118, 332, 579, 540, 389, 
173, 121, 553, 199, 784, 179, 228, 338, 312, 704, 390, 174, 554, 581, 393, 283, 122, 448, 353, 561, 203, 63, 340, 394, 527, 582, 556, 181, 295, 285, 232, 124, 205, 182, 643, 
562, 286, 585, 299, 354, 211, 401, 185, 396, 344, 586, 645, 593, 535, 240, 206, 95, 327, 564, 800, 402, 356, 307, 301, 417, 213, 568, 832, 588, 186, 646, 404, 227, 896, 594, 
418, 302, 649, 771, 360, 539, 111, 331, 214, 309, 188, 449, 217, 408, 609, 596, 551, 650, 229, 159, 420, 310, 541, 773, 610, 657, 333, 119, 600, 339, 218, 368, 652, 230, 
391, 313, 450, 542, 334, 233, 555, 774, 175, 123, 658, 612, 341, 777, 220, 314, 424, 395, 673, 583, 355, 287, 183, 234, 125, 557, 660, 616, 342, 316, 241, 778, 563, 345, 
452, 397, 403, 207, 674, 558, 785, 432, 357, 187, 236, 664, 624, 587, 780, 705, 126, 242, 565, 398, 346, 456, 358, 405, 303, 569, 244, 595, 189, 566, 676, 361, 706, 589, 
215, 786, 647, 348, 419, 406, 464, 680, 801, 362, 590, 409, 570, 788, 597, 572, 219, 311, 708, 598, 601, 651, 421, 792, 802, 611, 602, 410, 231, 688, 653, 248, 369, 190, 
364, 654, 659, 335, 480, 315, 221, 370, 613, 422, 425, 451, 614, 543, 235, 412, 343, 372, 775, 317, 222, 426, 453, 237, 559, 833, 804, 712, 834, 661, 808, 779, 617, 604, 
433, 720, 816, 836, 347, 897, 243, 662, 454, 318, 675, 618, 898, 781, 376, 428, 665, 736, 567, 840, 625, 238, 359, 457, 399, 787, 591, 678, 434, 677, 349, 245, 458, 666, 
620, 363, 127, 191, 782, 407, 436, 626, 571, 465, 681, 246, 707, 350, 599, 668, 790, 460, 249, 682, 573, 411, 803, 789, 709, 365, 440, 628, 689, 374, 423, 466, 793, 250, 
371, 481, 574, 413, 603, 366, 468, 655, 900, 805, 615, 684, 710, 429, 794, 252, 373, 605, 848, 690, 713, 632, 482, 806, 427, 904, 414, 223, 663, 692, 835, 619, 472, 455, 
796, 809, 714, 721, 837, 716, 864, 810, 606, 912, 722, 696, 377, 435, 817, 319, 621, 812, 484, 430, 838, 667, 488, 239, 378, 459, 622, 627, 437, 380, 818, 461, 496, 669, 
679, 724, 841, 629, 351, 467, 438, 737, 251, 462, 442, 441, 469, 247, 683, 842, 738, 899, 670, 783, 849, 820, 728, 928, 791, 367, 901, 630, 685, 844, 633, 711, 253, 691, 
824, 902, 686, 740, 850, 375, 444, 470, 483, 415, 485, 905, 795, 473, 634, 744, 852, 960, 865, 693, 797, 906, 715, 807, 474, 636, 694, 254, 717, 575, 913, 798, 811, 379, 
697, 431, 607, 489, 866, 723, 486, 908, 718, 813, 476, 856, 839, 725, 698, 914, 752, 868, 819, 814, 439, 929, 490, 623, 671, 739, 916, 463, 843, 381, 497, 930, 821, 726, 
961, 872, 492, 631, 729, 700, 443, 741, 845, 920, 382, 822, 851, 730, 498, 880, 742, 445, 471, 635, 932, 687, 903, 825, 500, 846, 745, 826, 732, 446, 962, 936, 475, 853, 
867, 637, 907, 487, 695, 746, 828, 753, 854, 857, 504, 799, 255, 964, 909, 719, 477, 915, 638, 748, 944, 869, 491, 699, 754, 858, 478, 968, 383, 910, 815, 976, 870, 917, 
727, 493, 873, 701, 931, 756, 860, 499, 731, 823, 922, 874, 918, 502, 933, 743, 760, 881, 494, 702, 921, 501, 876, 847, 992, 447, 733, 827, 934, 882, 937, 963, 747, 505, 
855, 924, 734, 829, 965, 938, 884, 506, 749, 945, 966, 755, 859, 940, 830, 911, 871, 639, 888, 479, 946, 750, 969, 508, 861, 757, 970, 919, 875, 862, 758, 948, 977, 923, 
972, 761, 877, 952, 495, 703, 935, 978, 883, 762, 503, 925, 878, 735, 993, 885, 939, 994, 980, 926, 764, 941, 967, 886, 831, 947, 507, 889, 984, 751, 942, 996, 971, 890, 
509, 949, 973, 1000, 892, 950, 863, 759, 1008, 510, 979, 953, 763, 974, 954, 879, 981, 982, 927, 995, 765, 956, 887, 985, 997, 986, 943, 891, 998, 766, 511, 988, 1001, 951, 
1002, 893, 975, 894, 1009, 955, 1004, 1010, 957, 983, 958, 987, 1012, 999, 1016, 767, 989, 1003, 990, 1005, 959, 1011, 1013, 895, 1006, 1014, 1017, 1018, 991, 1020, 
1007, 1015, 1019, 1021, 1022, 1023};


std::vector<std::vector<int>> KroneckerProduct(const std::vector<std::vector<int>>& first, 
                                       const std::vector<std::vector<int>>& second) {

    std::vector<std::vector<int>> result;
    for (int i = 0; i < first.size(); i++) {
        int num1 = first[i][0];
        int num2 = first[i][1];
        for (int k = 0; k < second.size(); k++) {
            std::vector<int> line1 = second[k];
            for (int l = 0; l < line1.size(); l++) line1[l] *= num1;
            std::vector<int> line2 = second[k];
            for (int l = 0; l < line2.size(); l++) line2[l] *= num2;
            std::vector<int> final_line;
            final_line.insert(final_line.end(), line1.begin(), line1.end());
            final_line.insert(final_line.end(), line2.begin(), line2.end());
            result.push_back(final_line);
        }
    }
    return result;
}

std::vector<std::vector<int>> PolarTransform(int n) { 
    std::vector<std::vector<int>> begin{{1, 0}, {1, 1}}; 
    if (n == 1) {
        return begin;
    }
    return KroneckerProduct(begin, PolarTransform(n - 1));
}

std::vector<int> PolarEncoding(const std::vector<int>& Message, 
                              const std::vector<std::vector<int>>& PolarMatrix) {
    std::vector<int> result;
    int columns = PolarMatrix[0].size();
    for (int i = 0; i < columns; i++) {
        int c = 0;
        for (int j = 0; j < PolarMatrix.size(); j++) {
            c = c ^ (Message[j] * PolarMatrix[j][i]);
        }
        result.push_back(c);
    }
    return result;
}
std::vector<int> ReliabilitySequenceForN(const int& N) {
    std::vector<int> result;
    for (int i = 0; i < ReliabilitySequence.size(); i++) {
        if (ReliabilitySequence[i] <= N-1) {
            result.push_back(ReliabilitySequence[i]);
        }
    }
    return result;
}

std::vector<int> AddFrozen(const std::vector<int>& Message, const int& N) {
    std::vector<int> result(N, 0);
    int k = Message.size();
    std::vector<int> seq = ReliabilitySequenceForN(N);
    sort(seq.begin() + N - k, seq.end());
    for (int i = N - k; i < N; i++) {
        result[seq[i]] = Message[i - N + k];
    }
    return result;
}

std::vector<int> IsFrozenNode(const std::vector<int>& RelSeq, const int& num_froz) {
    std::vector<int> result(RelSeq.size(), 0);
    int i = 0;
    while (i < num_froz) {
        result[RelSeq[i]] = 1;
        i++;
    }
    return result;
}

double sgn(const double& num) {
    if (num < 0.0) {
        return -1.0;
    } else if (num == 0.0) {
        return 0.0;
    }
    return 1.0;
}

double F(const double& a, const double& b) {
    return sgn(a)*sgn(b)*(std::min(std::abs(a), std::abs(b)));
}

double G(const double& a, const double& b, const double& c) {
    return b + (1 - 2 * c)*a;
}

std::vector<double> FuncFVectors(const std::vector<double>& first,
                                 const std::vector<double>& second) {
    std::vector<double> result;
    for (int i = 0; i < first.size(); i++) {
        result.push_back(F(first[i], second[i]));
    }
    return result;
}

std::vector<double> FuncGVectors(const std::vector<double>& first,
                                 const std::vector<double>& second, 
                                 const std::vector<double>& third) {
    std::vector<double> result;
    for (int i = 0; i < first.size(); i++) {
        result.push_back(G(first[i], second[i], third[i]));
    }
    return result;
}

std::vector<int> SumTwoVectors(const std::vector<int>& first, 
                                const std::vector<int>& second) {
    std::vector<int> res;
    for (int i = 0; i < first.size(); i++) {
        res.push_back(first[i] ^ second[i]);
    }
    res.insert(res.end(), second.begin(), second.end());
    return res;
}

std::vector<int> SC_Decoding(const std::vector<double>& CodeWord, const int& k) {
    
    int N = CodeWord.size();
    int depth_max = (int)log2(N);
    std::vector<int> RelSeq = ReliabilitySequenceForN(N);
    std::vector<int> IsFrozen = IsFrozenNode(RelSeq, N - k);

    std::vector<int> states(2*N-1, 0);
    std::vector<std::vector<double>> L(depth_max + 1, CodeWord);
    std::vector<std::vector<int>> Ucap(depth_max + 1, std::vector<int> (N, 0));  

    int depth = 0, node = 0;
    int flag = 0; // 0 means travel is not ended, 1 travel is ended

    while (flag == 0) {
        int CurNode = pow(2, depth) - 1 + node;
        if (depth == depth_max) { // if we are in leaf
            if (IsFrozen[node] == 1) { // if bit is frozen
                 Ucap[depth][node] = 0;
            }
             else {
                if (L[depth][node] >= 0) {
                     Ucap[depth][node] = 0;
                } else {
                     Ucap[depth][node] = 1;
                }
            }
         if (node == N - 1) {
             flag = 1;
         } else {
             node /= 2; depth--;
         }
        } 
        else { // if we are not in leaf
            if (states[CurNode] == 0) {
                int length_node = pow(2, depth_max - depth);
                std::vector<double> node_parent(length_node), a(length_node/2), b(length_node/2);
                std::copy(L[depth].begin() + length_node*node, 
                          L[depth].begin() + length_node *(node + 1), node_parent.begin());
                std::copy(node_parent.begin(), node_parent.begin()+length_node/2, a.begin() );
                std::copy(node_parent.begin()+ length_node/2, node_parent.end(), b.begin());
                depth++; node *= 2; length_node /= 2;
                std::vector<double> FuncF = FuncFVectors(a, b);
                std::copy(FuncF.begin(), FuncF.end(), L[depth].begin() + length_node*node);
                states[CurNode] = 1;
            }
            else if (states[CurNode] == 1) {
                int length_node = pow(2, depth_max - depth);
                std::vector<double> node_parent(length_node), a(length_node/2), b(length_node/2);
                std::copy(L[depth].begin() + length_node*node, 
                          L[depth].begin() + length_node *(node + 1), node_parent.begin());
                std::copy(node_parent.begin(), node_parent.begin()+length_node/2, a.begin() );
                std::copy(node_parent.begin()+ length_node/2, node_parent.end(), b.begin());

                int left_child_depth = depth + 1;
                int left_child_node = node * 2;
                int left_length_node =  length_node / 2;
                std::vector<double> CurUCap(left_length_node);
                std::copy(Ucap[left_child_depth].begin() + left_child_node*left_length_node,
                Ucap[left_child_depth].begin() + left_length_node*(left_child_node+1), CurUCap.begin());

                depth++; node = node * 2 + 1; length_node /= 2;
                std::vector<double> FuncG = FuncGVectors(a, b, CurUCap);
                std::copy(FuncG.begin(), FuncG.end(), L[depth].begin() + length_node*node);
                states[CurNode] = 2;
            }
            else  {
                int length_node = pow(2, depth_max - depth);
                int gen_length_node = length_node / 2, gen_depth = depth + 1;
                int left_node = 2 * node, right_node = 2 * node + 1;
                std::vector<int> Ucap_left(gen_length_node), Ucap_right(gen_length_node);
                std::copy(Ucap[gen_depth].begin() + gen_length_node*left_node,
                          Ucap[gen_depth].begin() + gen_length_node*(left_node + 1),
                          Ucap_left.begin());
                std::copy(Ucap[gen_depth].begin() + gen_length_node*right_node,
                          Ucap[gen_depth].begin() + gen_length_node*(right_node + 1),
                          Ucap_right.begin()); 
                std::vector<int> GetUcap = SumTwoVectors(Ucap_left, Ucap_right); 
                std::copy(GetUcap.begin(), GetUcap.end(), Ucap[depth].begin() + length_node*node);        
                node /= 2; depth--;
            }
        }
    }
    std::vector<int> result;
    for (int i = 0; i < Ucap[depth_max].size(); i++) {
        if (IsFrozen[i] == 0) {
            result.push_back(Ucap[depth_max][i]);
        }
    }
    return result;
}

void LShiftVector(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); i++) {
        vec[i-1] = vec[i];
    }
    vec[vec.size() - 1] = 0;
}

std::vector<int> LShiftVectorOffset(std::vector<int> vec, int offset) {
    for (int i = 0; i < offset; i++) {
        LShiftVector(vec);
    }
    return vec;
}

void RShiftVector(std::vector<int> &vec) {
    for (int i = vec.size() - 2; i >= 0; i--) {
        vec[i+1] = vec[i];
    }
    vec[0] = 0;
}

std::vector<int> RShiftVectorOffset(std::vector<int> vec, int offset) {
    for (int i = 0; i < offset; i++) {
        RShiftVector(vec);
    }
    return vec;
}


std::vector<int> GeneratePolynom(int CRC_size) {
    std::vector<int> result;
    switch (CRC_size) {
    case 8:
        result = {0, 0, 0, 0, 0, 1, 1, 1};
        break;
    case 16:
        result = {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1};
        break;
    case 32:
        result = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
        break;
    }
     
    return result;
}


std::vector<std::vector<int>> GenerateVectors(int CRC_size) {
    std::vector<std::vector<int>> result;
    for (int j = 0; j < 256; j ++) {
        std::vector<int> vec;
        for (int i = 7; i >= 0; i--) {
            if (j & (1 << i)) {
                vec.push_back(1);
            } else {
                vec.push_back(0);
            }
        }
        result.push_back(vec);
    }
    return result;

}

std::vector<int> operator^ (const std::vector<int>& first,const std::vector<int>& second) {
    std::vector<int> result;
    int i = first.size() - 1, j = second.size() - 1;
    while (i >= 0 && j >= 0) {
        result.push_back(first[i] ^ second[j]);
        i--; j--;
    }
    std::reverse(result.begin(), result.end());
    if (i >= 0) {
        result.insert(result.begin(), first.begin(), first.begin() + i + 1);
    }
    if (j >= 0) {
        result.insert(result.begin(), second.begin(), second.begin() + j + 1);
    }
    return result;
}

std::map<std::vector<int>, std::vector<int>> GenerateTable(const std::vector<int>& Gpolynom, 
                                                           int CRC_size) {
    std::map<std::vector<int>, std::vector<int>> result;
    std::vector<std::vector<int>> all_vectors = GenerateVectors(CRC_size);
    for (auto vec : all_vectors) {
        std::vector<int> copy_vec = vec;
        
        std::vector<int> zero_vector(CRC_size - 8, 0);
        vec.insert(vec.end(), zero_vector.begin(), zero_vector.end());
        for (int i = 0; i < 8; i++) {
            if (vec[0] == 1) {
                LShiftVector(vec);
                vec = vec ^ Gpolynom;
            } else {
                LShiftVector(vec);
            }
        }
        result[copy_vec] = vec;
    }
    return result;

}

std::vector<int> Get_CRC(std::vector<int> message, int CRC_size) {
    std::vector<int> G = GeneratePolynom(CRC_size); // generating polynom
    std::map<std::vector<int>, std::vector<int>> table = GenerateTable(G, CRC_size);

    if (message.size() % 8 != 0) {
        int num_to_add = 8 - (message.size() % 8);
        std::vector<int> zeros(num_to_add, 0);
        message.insert(message.begin(), zeros.begin(), zeros.end());
    }

    std::vector<int> begin(CRC_size, 0);
    for (int i = 0; i + 8 - 1 < message.size(); i += 8) {
        std::vector<int> PartMsg;
        std::copy(message.begin() + i, message.begin()+i+8, std::back_inserter(PartMsg));
        std::vector<int> zero_vec (CRC_size - 8, 0);
        PartMsg.insert(PartMsg.begin(), zero_vec.begin(), zero_vec.end());
        std::vector<int> pos;
        std::vector<int> k = LShiftVectorOffset(PartMsg, CRC_size - 8);
        pos = RShiftVectorOffset((begin ^ LShiftVectorOffset(PartMsg, CRC_size - 8)), CRC_size - 8);
        pos.erase(pos.begin(), pos.end() - 8); 
        begin = LShiftVectorOffset(begin, 8) ^ table[pos];
    }

    return begin;

}

bool Check_CRC(std::vector<int> message, int CRC_size) {
    if (message.size() % 8 != 0) {
        int num_to_add = 8 - (message.size() % 8);
        std::vector<int> zeros(num_to_add, 0);
        message.insert(message.begin(), zeros.begin(), zeros.end());
    }


    message = Get_CRC(message, CRC_size);
    std::vector<int> zero_vector(CRC_size, 0);
    if (message == zero_vector) {
        return true;
    }
    return false;
}
using vector3d_double = std::vector<std::vector<std::vector<double>>>;
using vector3d_int = std::vector<std::vector<std::vector<int>>>;

std::vector<std::vector<int>> SCList(const std::vector<double>& CodeWord, const int& k, const int& decod_num) {
    int N = CodeWord.size();
    int depth_max = (int)log2(N);
    std::vector<int> RelSeq = ReliabilitySequenceForN(N);
    std::vector<int> IsFrozen = IsFrozenNode(RelSeq, N - k);

    std::vector<int> states(2*N-1, 0);

    vector3d_double L(decod_num, std::vector<std::vector<double>> 
                                     (depth_max+1, CodeWord));

    vector3d_int Ucap(decod_num, std::vector<std::vector<int>>
                         (depth_max + 1, std::vector<int> (N, 0)));

    std::vector<double> PathMetric_old(decod_num, std::numeric_limits<double>::max());
    std::vector<double> PathMetric_new(decod_num, std::numeric_limits<double>::max());
    std::vector<double> PathMetric(decod_num, std::numeric_limits<double>::max());
    std::vector<double> DMetric(decod_num);
    PathMetric[0] = 0;  

    int depth = 0, node = 0;
    int flag = 0; // 0 means travel is not ended, 1 travel is ended


    while (flag == 0) {
        int CurNode = pow(2, depth) - 1 + node;
        if (depth == depth_max) { // if we are in leaf
            for (int i = 0; i < decod_num; i++) {
                DMetric[i] = L[i][depth][node];
            }
            if (IsFrozen[node] == 1) { // if bit is frozen
                 for (int i = 0; i < decod_num; i++) {
                    Ucap[i][depth][node] = 0;
                 }
                 for (int i = 0; i < decod_num; i++) {
                    if (DMetric[i] < 0) {
                        if (PathMetric[i] != std::numeric_limits<double>::max()) {
                            PathMetric[i] = PathMetric[i] - DMetric[i];
                        }
                    }
                 }
            }
             else {
                // make vector of pos and update pm
                std::vector<bool> Dec(decod_num, false);
                std::vector<bool> Pos(decod_num, false);
                for (int i = 0; i < decod_num; i++) {
                    Dec[i] = (DMetric[i] < 0);
                }
                PathMetric_old = PathMetric;
                PathMetric_new = PathMetric;
                for (int i = 0; i < decod_num; i++) {
                    if (PathMetric_new[i] != std::numeric_limits<double>::max()) {
                        PathMetric_new[i] += std::abs(DMetric[i]);
                    }
                }
                std::vector<double> ConcVector(PathMetric_old);
                std::vector<int> Positions(decod_num);
                ConcVector.insert(ConcVector.end(), PathMetric_new.begin(), PathMetric_new.end());
                std::map <double, int> my_map;
                for (int i = 0; i < ConcVector.size(); i++) {
                    my_map[ConcVector[i]] = i;
                }

                int cnt = 0;
                for(const auto& num : my_map) {
                    if (cnt >= decod_num) {
                        break;
                    }
                    PathMetric[cnt] = num.first;
                    Positions[cnt] = num.second;
                    cnt++;
                }

                for (int i = 0; i < decod_num; i++) {
                    Pos[i] = (Positions[i] >= decod_num);
                    if (Pos[i]) {
                        Positions[i] -= decod_num;
                    }
                }

                std::vector<bool> CopyDec(Dec);

                for(int i = 0; i < decod_num; i++) {
                    Dec[i] = CopyDec[Positions[i]];
                    if (Pos[i]) {
                        Dec[i] = !Dec[i];
                    }
                }

                vector3d_double L_copy(decod_num);
                vector3d_int Ucap_copy(decod_num);

                for  (int i = 0; i < decod_num; i++) {
                    L_copy[i] = L[i];
                    Ucap_copy[i] = Ucap[i];
                }

                for (int i = 0; i < decod_num; i++) {
                    L[i] = L_copy[Positions[i]];
                    Ucap[i] = Ucap_copy[Positions[i]];
                    Ucap[i][depth][node] = Dec[i];
                }
            }
         if (node == N - 1) {
             flag = 1;
         } else {
             node /= 2; depth--;
         }
        } 
        else { // if we are not in leaf
            if (states[CurNode] == 0) {
                int length_node = pow(2, depth_max - depth);
                std::vector<std::vector<double>> 
                node_parent (decod_num, std::vector<double>(length_node)), 
                a(decod_num, std::vector<double>(length_node / 2)), 
                b(decod_num, std::vector<double>(length_node / 2));

                for (int i = 0; i < decod_num; i++ ) {
                std::copy(L[i][depth].begin() + length_node*node, 
                          L[i][depth].begin() + length_node *(node + 1), node_parent[i].begin());
                std::copy(node_parent[i].begin(), node_parent[i].begin()+length_node/2, a[i].begin() );
                std::copy(node_parent[i].begin()+ length_node/2, node_parent[i].end(), b[i].begin());
                }
                depth++; node *= 2; length_node /= 2;
                std::vector<std::vector<double>> FuncF(decod_num);
                for (int i = 0; i < decod_num; i++) {
                    FuncF[i] = FuncFVectors(a[i], b[i]);
                    std::copy(FuncF[i].begin(), FuncF[i].end(), 
                        L[i][depth].begin() + length_node*node);
                }
                states[CurNode] = 1;
            }
            else if (states[CurNode] == 1) {
                int length_node = pow(2, depth_max - depth);
                std::vector<std::vector<double>>
                node_parent(decod_num, std::vector<double>(length_node)),
                a(decod_num, std::vector<double>(length_node / 2)), 
                b(decod_num, std::vector<double>(length_node / 2));

                for (int i = 0; i < decod_num; i++) {
                    std::copy(L[i][depth].begin() + length_node*node, 
                          L[i][depth].begin() + length_node *(node + 1), node_parent[i].begin());
                    std::copy(node_parent[i].begin(), node_parent[i].begin()+length_node/2, a[i].begin() );
                    std::copy(node_parent[i].begin()+ length_node/2, node_parent[i].end(), b[i].begin());
                }

                int left_child_depth = depth + 1;
                int left_child_node = node * 2;
                int left_length_node =  length_node / 2;
                std::vector<std::vector<double>> CurUCap(decod_num, std::vector<double>(left_length_node));
                
                for (int i = 0; i < decod_num; i++) {
                    std::copy(Ucap[i][left_child_depth].begin() + left_child_node*left_length_node,
                        Ucap[i][left_child_depth].begin() + left_length_node*(left_child_node+1), CurUCap[i].begin());
                }

                depth++; node = node * 2 + 1; length_node /= 2;
                std::vector<std::vector<double>> FuncG(decod_num);
                for (int i = 0; i < decod_num; i++) {
                    FuncG[i] = FuncGVectors(a[i], b[i], CurUCap[i]);
                    std::copy(FuncG[i].begin(), FuncG[i].end(), L[i][depth].begin() + length_node*node);
                } 
                states[CurNode] = 2;
            }
            else  {
                int length_node = pow(2, depth_max - depth);
                int gen_length_node = length_node / 2, gen_depth = depth + 1;
                int left_node = 2 * node, right_node = 2 * node + 1;
                std::vector<std::vector<int>> 
                Ucap_left (decod_num, std::vector<int>(gen_length_node)), 
                Ucap_right(decod_num, std::vector<int>(gen_length_node));
                
                for (int i = 0; i < decod_num; i++) {
                    std::copy(Ucap[i][gen_depth].begin() + gen_length_node*left_node,
                          Ucap[i][gen_depth].begin() + gen_length_node*(left_node + 1),
                          Ucap_left[i].begin());
                    std::copy(Ucap[i][gen_depth].begin() + gen_length_node*right_node,
                          Ucap[i][gen_depth].begin() + gen_length_node*(right_node + 1),
                          Ucap_right[i].begin()); 
                }

                std::vector<std::vector<int>> GetUcap(decod_num);
                for (int i = 0; i < decod_num; i++) {
                    GetUcap[i] = SumTwoVectors(Ucap_left[i], Ucap_right[i]);
                    std::copy(GetUcap[i].begin(), GetUcap[i].end(), 
                        Ucap[i][depth].begin() + length_node*node);
                }        
                node /= 2; depth--;
            }
        }
    }

    std::vector<std::vector<int>> result;

    for (int j = 0; j < decod_num; j++) {
        std::vector<int> temp;
        for (int i = 0; i < Ucap[j][depth_max].size(); i++) {
            if (IsFrozen[i] == 0) {
                temp.push_back(Ucap[j][depth_max][i]);
            }
        }
        result.push_back(temp);
    }
    return result;

}


std::vector<int> Msg_Correct_CRC(const std::vector<std::vector<int>>& PosibleWords, const int& CRC_size) {
    for (auto word : PosibleWords) {
        if (Check_CRC(word, CRC_size)) {
            return word;
        }
    }
    return PosibleWords[0]; // take random word
}


bool AllEquals(const std::vector<int>& vec, const int& left,const int& right, const int& element) {
    bool flag = true;
    for (int i = left; i < right; i++) {
        if (vec[i] != element) {
            flag = false;
            break;
        }
    }
    return flag;
}


std::vector<int> least_reliable_bit(const vector3d_double& L, const int& depth, const int& length_node,  
                                    const int& layer, const int& node, const int& num_least_bits) {
    std::vector<int> result;
    std::vector<double> copy_vector(length_node);

    std::copy(L[layer][depth].begin() + node * length_node,
              L[layer][depth].begin() + (node + 1) * length_node, copy_vector.begin());


    std::sort(copy_vector.begin(), copy_vector.end(), [](double i, double j) { return std::abs(i) < std::abs(j); });
    int min_size = std::min(num_least_bits, (int)copy_vector.size());
    copy_vector.resize(min_size);
    for (auto num : copy_vector) {
        for (int i = node*length_node; i < (node + 1)*length_node; i++) {
            if (num == L[layer][depth][i]) {
                result.push_back(i % length_node);
            }
        }
    }
    return result;
}



std::vector<std::vector<int>> Fast_SCL(const std::vector<double>& CodeWord,const int& k, const int& decod_num) {
    int N = CodeWord.size();
    int depth_max = (int)log2(N);

    std::vector<int> RelSeq = ReliabilitySequenceForN(N);
    std::vector<int> IsFrozen = IsFrozenNode(RelSeq, N - k);
    std::vector<std::vector<int>> Answers(decod_num, std::vector<int> (N, 0));

    std::vector<int> states(2*N-1, 0);

    vector3d_double L(decod_num, std::vector<std::vector<double>>
            (depth_max+1, CodeWord));

    vector3d_int Ucap(decod_num, std::vector<std::vector<int>>
            (depth_max + 1, std::vector<int> (N, 0)));

    std::vector<double> PathMetric_old(decod_num, std::numeric_limits<double>::max());
    std::vector<double> PathMetric_new(decod_num, std::numeric_limits<double>::max());
    std::vector<double> PathMetric(decod_num, std::numeric_limits<double>::max());
    std::vector<double> DMetric(decod_num);
    PathMetric[0] = 0;

    int depth = 0, node = 0;
    int flag = 0; // 0 means travel is not ended, 1 travel is ended


    while (flag == 0) {
        int CurNode = pow(2, depth) - 1 + node;
        if (depth == depth_max) { // if we are in leaf
            for (int i = 0; i < decod_num; i++) {
                DMetric[i] = L[i][depth][node];
            }
            if (IsFrozen[node] == 1) { // if bit is frozen
                for (int i = 0; i < decod_num; i++) {
                    Ucap[i][depth][node] = 0;
                }
                for (int i = 0; i < decod_num; i++) {
                    if (DMetric[i] < 0) {
                        if (PathMetric[i] != std::numeric_limits<double>::max()) {
                            PathMetric[i] = PathMetric[i] - DMetric[i];
                        }
                    }
                }
            }
            else {
                // make vector of pos and update pm
                std::vector<bool> Dec(decod_num, false);
                std::vector<bool> Pos(decod_num, false);
                for (int i = 0; i < decod_num; i++) {
                    Dec[i] = (DMetric[i] < 0);
                }
                PathMetric_old = PathMetric;
                PathMetric_new = PathMetric;
                for (int i = 0; i < decod_num; i++) {
                    if (PathMetric_new[i] != std::numeric_limits<double>::max()) {
                        PathMetric_new[i] += std::abs(DMetric[i]);
                    }
                }
                std::vector<double> ConcVector(PathMetric_old);
                std::vector<int> Positions(decod_num);
                ConcVector.insert(ConcVector.end(), PathMetric_new.begin(), PathMetric_new.end());
                std::map <double, int> my_map;
                for (int i = 0; i < ConcVector.size(); i++) {
                    my_map[ConcVector[i]] = i;
                }

                int cnt = 0;
                for(const auto& num : my_map) {
                    if (cnt >= decod_num) {
                        break;
                    }
                    PathMetric[cnt] = num.first;
                    Positions[cnt] = num.second;
                    cnt++;
                }

                for (int i = 0; i < decod_num; i++) {
                    Pos[i] = (Positions[i] >= decod_num);
                    if (Pos[i]) {
                        Positions[i] -= decod_num;
                    }
                }

                std::vector<bool> CopyDec(Dec);

                for(int i = 0; i < decod_num; i++) {
                    Dec[i] = CopyDec[Positions[i]];
                    if (Pos[i]) {
                        Dec[i] = !Dec[i];
                    }
                }

                vector3d_double L_copy(decod_num);
                vector3d_int Ucap_copy(decod_num);

                for  (int i = 0; i < decod_num; i++) {
                    L_copy[i] = L[i];
                    Ucap_copy[i] = Ucap[i];
                }

                for (int i = 0; i < decod_num; i++) {
                    L[i] = L_copy[Positions[i]];
                    Ucap[i] = Ucap_copy[Positions[i]];
                }

                for (int i = 0; i < decod_num; i++) {
                    Ucap[i][depth][node] = Dec[i];
                }
            }
            if (node == N - 1) {
                flag = 1;
            } else {
                node /= 2; depth--;
            }
        }
        else { // if we are not in leaf
            if (states[CurNode] == 0) {
                int length_node = pow(2, depth_max - depth);
                if (AllEquals(IsFrozen, node*length_node, (node + 1)*length_node, 1)) {
                    // Rate0
                    // states[CurNode] = 2
                    for (int i = 0; i < decod_num; i++) {
                        double sum = 0.0;
                        for (int j = node*length_node; j < (node + 1)*length_node; j++) {
                            if (L[i][depth][j] < 0.0) {
                                sum += L[i][depth][j];
                            }
                        }
                        if (PathMetric[i] != std::numeric_limits<double>::max()) {
                            PathMetric[i] = PathMetric[i] - sum;
                        }
                    }

                    if (node == std::pow(2, depth) - 1) {
                        flag = 1;
                    }
                    node /= 2; depth--;
                    states[CurNode] = 3;

                }
                else if (AllEquals(IsFrozen, node*length_node, (node + 1)*length_node, 0)) {
                    //Rate1
                    std::vector<std::vector<bool>> Dec(decod_num * 4, std::vector<bool> (length_node, false));
                    std::vector<bool> Pos(decod_num, false);
                    std::vector<std::vector<int>> two_index(decod_num, std::vector<int>(2, 0));
                    std::vector<std::vector<int>> G = PolarTransform(depth_max - depth);


                    for (int i = 0; i < decod_num; i++) {
                        two_index[i] = least_reliable_bit(L, depth, length_node, i, node, 2);
                    }


                    for (int i = 0; i < decod_num; i++) {
                        std::vector<int> dec_0(length_node, 0);
                        for (int j = node*length_node; j < (node+1)*length_node; j++) {
                            if (L[i][depth][j] < 0) {
                                dec_0[j - node*length_node] = 1;
                            }
                        }
                        for (int j = 0; j < 4; j++) {
                            std::copy(dec_0.begin(), dec_0.end(), Dec[4*i+j].begin());
                        }

                        Dec[4*i+1][two_index[i][0]] = !Dec[4*i+1][two_index[i][0]];
                        Dec[4*i+2][two_index[i][1]] = !Dec[4*i+2][two_index[i][1]];
                        Dec[4*i+3][two_index[i][0]] = !Dec[4*i+3][two_index[i][0]];
                        Dec[4*i+3][two_index[i][1]] = !Dec[4*i+3][two_index[i][1]];

                    }
                    std::vector<double> PathMetric_4(4 * decod_num, 0.0);

                    for (int i = 0; i < decod_num; i++) {
                        for (int j = 0; j < 4; j++) {
                            PathMetric_4[4*i+j] = PathMetric[i];
                        }
                        PathMetric_4[4*i+1] += std::abs(L[i][depth][length_node * node + two_index[i][0]]);
                        PathMetric_4[4*i+2] += std::abs(L[i][depth][length_node * node + two_index[i][1]]);
                        PathMetric_4[4*i+3] += std::abs(L[i][depth][length_node * node + two_index[i][0]]);
                        PathMetric_4[4*i+3] += std::abs(L[i][depth][length_node * node + two_index[i][1]]);
                    }

                    std::vector<int> Positions(decod_num);
                    std::vector<std::vector<int>> Decision(decod_num, std::vector<int> (length_node, 0));
                    std::map <double, int> my_map;
                    for (int i = 0; i < PathMetric_4.size(); i++) {
                        my_map[PathMetric_4[i]] = i;
                    }

                    int cnt = 0;
                    for(const auto& num : my_map) {
                        if (cnt >= decod_num) {
                            break;
                        }
                        PathMetric[cnt] = num.first;
                        Positions[cnt] = num.second;
                        cnt++;
                    }

                    cnt = 0;
                    for (const auto& pos : Positions) {
                        std::copy(Dec[pos].begin(), Dec[pos].end(), Decision[cnt].begin());
                        cnt++;
                    }

                    for (auto& pos : Positions) {
                        pos = pos / 4;
                    }

                    vector3d_double L_copy(decod_num);
                    vector3d_int Ucap_copy(decod_num);
                    std::vector<std::vector<int>> copy_answers(decod_num);

                    for  (int i = 0; i < decod_num; i++) {
                        L_copy[i] = L[i];
                        Ucap_copy[i] = Ucap[i];
                        copy_answers[i] = Answers[i];
                    }

                    for (int i = 0; i < decod_num; i++) {
                        L[i] = L_copy[Positions[i]];
                        Ucap[i] = Ucap_copy[Positions[i]];
                        Answers[i] = copy_answers[Positions[i]];
                    }

                    for (int i = 0; i < decod_num; i++) {
                        std::copy(Decision[i].begin(), Decision[i].end(),
                                  Ucap[i][depth].begin() + length_node * node);
                        Decision[i] = PolarEncoding(Decision[i], G);
                        std::copy(Decision[i].begin(), Decision[i].end(),
                                                        Answers[i].begin() + node * length_node);

                    }





                    if (node == std::pow(2, depth) - 1) {
                        flag = 1;
                    }
                    node /= 2; depth--;
                    states[CurNode] = 3;

                }
                else if (AllEquals(IsFrozen, node*length_node, (node + 1)*length_node - 1, 1) &&
                         IsFrozen[(node + 1)*length_node - 1] == 0) {
                    //Repetition

                    std::vector<double> DoublePathMetric(2 * PathMetric.size());
                    std::copy(PathMetric.begin(), PathMetric.end(), DoublePathMetric.begin());
                    std::copy(PathMetric.begin(), PathMetric.end(), DoublePathMetric.begin() + PathMetric.size());
                    std::vector<std::vector<int>> G = PolarTransform(depth_max - depth);

                    for (int i = 0; i < decod_num; i++) {
                        for (int j = length_node * node; j < (node + 1)*length_node; j++) {
                            if (L[i][depth][j] < 0.0) {
                                DoublePathMetric[i] -= L[i][depth][j];
                            }
                        }
                    }

                    for (int i = decod_num; i < 2 * decod_num; i++) {
                        for (int j = length_node * node; j < (node + 1)*length_node; j++) {
                            if (L[i - decod_num][depth][j] >= 0.0) {
                                DoublePathMetric[i] += L[i - decod_num][depth][j];
                            }
                        }
                    }

                    std::vector<int> Positions(decod_num);
                    std::map <double, int> my_map;
                    for (int i = 0; i < DoublePathMetric.size(); i++) {
                        my_map[DoublePathMetric[i]] = i;
                    }

                    int cnt = 0;
                    for(const auto& num : my_map) {
                        if (cnt >= decod_num) {
                            break;
                        }
                        PathMetric[cnt] = num.first;
                        Positions[cnt] = num.second;
                        cnt++;
                    }

                    std::vector<bool> Dec(decod_num, false);
                    for (int i = 0; i < decod_num; i++) {
                        Dec[i] = (Positions[i] >= decod_num);
                        if (Dec[i]) {
                            Positions[i] -= decod_num;
                        }
                    }

                    vector3d_double L_copy(decod_num);
                    vector3d_int Ucap_copy(decod_num);
                    std::vector<std::vector<int>> copy_answers(decod_num);

                    for  (int i = 0; i < decod_num; i++) {
                        L_copy[i] = L[i];
                        Ucap_copy[i] = Ucap[i];
                        copy_answers[i] = Answers[i];
                    }

                    for (int i = 0; i < decod_num; i++) {
                        L[i] = L_copy[Positions[i]];
                        Ucap[i] = Ucap_copy[Positions[i]];
                        Answers[i] = copy_answers[Positions[i]];
                    }

                    std::vector<std::vector<int>> Decision(decod_num, std::vector<int> (length_node, 0));

                    for  (int i = 0; i < decod_num; i++) {
                        for (int j = node * length_node; j < (node+1)*length_node; j++) {
                            Decision[i][j - node * length_node] = Dec[i];
                            Ucap[i][depth][j] = Decision[i][j - node*length_node];
                        }
                        Decision[i] = PolarEncoding(Decision[i], G);
                        std::copy(Decision[i].begin(), Decision[i].end(),
                                  Answers[i].begin() + node * length_node);
                    }

                    if (node == std::pow(2, depth) - 1) {
                        break;
                    }


                    node /= 2; depth--;
                    states[CurNode] = 3;

                }
                else if (IsFrozen[node*length_node] == 1 &&
                         AllEquals(IsFrozen, node*length_node + 1, (node + 1)*length_node, 0) )   {
                    // SPC
                    std::vector<std::vector<bool>> Dec(decod_num * 8, std::vector<bool> (length_node, false));
                    std::vector<double> PathMetric_8(8 * decod_num, 0.0);
                    std::vector<bool> Pos(decod_num, false);
                    std::vector<std::vector<int>> four_index(decod_num, std::vector<int>(4, 0));
                    std::vector<std::vector<int>> G = PolarTransform(depth_max - depth);

                    for (int i = 0; i < decod_num; i++) {
                        four_index[i] = least_reliable_bit(L, depth, length_node, i, node, 4);
                    }


                    for (int i = 0; i < decod_num; i++) {
                        std::vector<int> dec_0(length_node, 0);
                        for (int j = node*length_node; j < (node+1)*length_node; j++) {
                            if (L[i][depth][j] < 0) {
                                dec_0[j - node*length_node] = 1;
                            }
                        }
                        int parity=0;
                        for (int j = 0; j < length_node; j++) {
                            parity ^= dec_0[j];
                        }

                        int one_index = four_index[i][0];
                        dec_0[one_index] ^= parity;

                        for (int j = 0; j < 8; j++) {
                            std::copy(dec_0.begin(), dec_0.end(), Dec[8*i+j].begin());
                            PathMetric_8[8*i+j] = PathMetric[i] +
                                    parity * std::abs(L[i][depth][length_node * node + four_index[i][0]]);
                        }

                        Dec[8*i+1][four_index[i][0]] = !Dec[8*i+1][four_index[i][0]];
                        Dec[8*i+1][four_index[i][1]] = !Dec[8*i+1][four_index[i][1]];

                        Dec[8*i+2][four_index[i][0]] = !Dec[8*i+2][four_index[i][0]];
                        Dec[8*i+2][four_index[i][2]] = !Dec[8*i+2][four_index[i][2]];

                        Dec[8*i+3][four_index[i][0]] = !Dec[8*i+3][four_index[i][0]];
                        Dec[8*i+3][four_index[i][3]] = !Dec[8*i+3][four_index[i][3]];

                        Dec[8*i+4][four_index[i][1]] = !Dec[8*i+4][four_index[i][1]];
                        Dec[8*i+4][four_index[i][2]] = !Dec[8*i+4][four_index[i][2]];

                        Dec[8*i+5][four_index[i][1]] = !Dec[8*i+5][four_index[i][1]];
                        Dec[8*i+5][four_index[i][3]] = !Dec[8*i+5][four_index[i][3]];

                        Dec[8*i+6][four_index[i][2]] = !Dec[8*i+6][four_index[i][2]];
                        Dec[8*i+6][four_index[i][3]] = !Dec[8*i+6][four_index[i][3]];

                        Dec[8*i+7][four_index[i][0]] = !Dec[8*i+7][four_index[i][0]];
                        Dec[8*i+7][four_index[i][1]] = !Dec[8*i+7][four_index[i][1]];
                        Dec[8*i+7][four_index[i][2]] = !Dec[8*i+7][four_index[i][2]];
                        Dec[8*i+7][four_index[i][3]] = !Dec[8*i+7][four_index[i][3]];



                        PathMetric_8[8*i+1] += (1-parity) * std::abs(L[i][depth][length_node * node + four_index[i][0]]);
                        PathMetric_8[8*i+1] += std::abs(L[i][depth][length_node * node + four_index[i][1]]);

                        PathMetric_8[8*i+2] += (1-parity) * std::abs(L[i][depth][length_node * node + four_index[i][0]]);
                        PathMetric_8[8*i+2] += std::abs(L[i][depth][length_node * node + four_index[i][2]]);

                        PathMetric_8[8*i+3] += (1-parity) * std::abs(L[i][depth][length_node * node + four_index[i][0]]);
                        PathMetric_8[8*i+3] += std::abs(L[i][depth][length_node * node + four_index[i][3]]);

                        PathMetric_8[8*i+4] += std::abs(L[i][depth][length_node * node + four_index[i][1]]);
                        PathMetric_8[8*i+4] += std::abs(L[i][depth][length_node * node + four_index[i][2]]);

                        PathMetric_8[8*i+5] += std::abs(L[i][depth][length_node * node + four_index[i][1]]);
                        PathMetric_8[8*i+5] += std::abs(L[i][depth][length_node * node + four_index[i][3]]);

                        PathMetric_8[8*i+6] += std::abs(L[i][depth][length_node * node + four_index[i][2]]);
                        PathMetric_8[8*i+6] += std::abs(L[i][depth][length_node * node + four_index[i][3]]);

                        PathMetric_8[8*i+7] += (1-parity) * std::abs(L[i][depth][length_node * node + four_index[i][0]]);
                        PathMetric_8[8*i+7] += std::abs(L[i][depth][length_node * node + four_index[i][1]]);
                        PathMetric_8[8*i+7] += std::abs(L[i][depth][length_node * node + four_index[i][2]]);
                        PathMetric_8[8*i+7] += std::abs(L[i][depth][length_node * node + four_index[i][3]]);
                    }

                    std::vector<int> Positions(decod_num);
                    std::vector<std::vector<int>> Decision(decod_num, std::vector<int> (length_node, 0));
                    std::map <double, int> my_map;
                    for (int i = 0; i < PathMetric_8.size(); i++) {
                        my_map[PathMetric_8[i]] = i;
                    }

                    int cnt = 0;
                    for(const auto& num : my_map) {
                        if (cnt >= decod_num) {
                            break;
                        }
                        PathMetric[cnt] = num.first;
                        Positions[cnt] = num.second;
                        cnt++;
                    }

                    cnt = 0;
                    for (const auto& pos : Positions) {
                        std::copy(Dec[pos].begin(), Dec[pos].end(), Decision[cnt].begin());
                        cnt++;
                    }

                    for (auto& pos : Positions) {
                        pos = pos / 8;
                    }

                    vector3d_double L_copy(decod_num);
                    vector3d_int Ucap_copy(decod_num);
                    std::vector<std::vector<int>> copy_answers(decod_num);

                    for  (int i = 0; i < decod_num; i++) {
                        L_copy[i] = L[i];
                        Ucap_copy[i] = Ucap[i];
                        copy_answers[i] = Answers[i];
                    }

                    for (int i = 0; i < decod_num; i++) {
                        L[i] = L_copy[Positions[i]];
                        Ucap[i] = Ucap_copy[Positions[i]];
                        Answers[i] = copy_answers[Positions[i]];
                    }

                    for (int i = 0; i < decod_num; i++) {
                        std::copy(Decision[i].begin(), Decision[i].end(),
                                  Ucap[i][depth].begin() + length_node * node);
                        Decision[i] = PolarEncoding(Decision[i], G);
                        std::copy(Decision[i].begin(), Decision[i].end(),
                                  Answers[i].begin() + node * length_node);

                    }

                    if (node == std::pow(2, depth) - 1) {
                        flag = 1;
                    }

                    node /= 2; depth--;
                    states[CurNode] = 3;
                }
                else {
                    std::vector<std::vector<double>>
                            node_parent (decod_num, std::vector<double>(length_node)),
                            a(decod_num, std::vector<double>(length_node / 2)),
                            b(decod_num, std::vector<double>(length_node / 2));

                    for (int i = 0; i < decod_num; i++ ) {
                        std::copy(L[i][depth].begin() + length_node*node,
                                  L[i][depth].begin() + length_node *(node + 1), node_parent[i].begin());
                        std::copy(node_parent[i].begin(), node_parent[i].begin()+length_node/2, a[i].begin() );
                        std::copy(node_parent[i].begin()+ length_node/2, node_parent[i].end(), b[i].begin());
                    }
                    depth++; node *= 2; length_node /= 2;
                    std::vector<std::vector<double>> FuncF(decod_num);
                    for (int i = 0; i < decod_num; i++) {
                        FuncF[i] = FuncFVectors(a[i], b[i]);
                        std::copy(FuncF[i].begin(), FuncF[i].end(),
                                  L[i][depth].begin() + length_node*node);
                    }
                    states[CurNode] = 1;
                }
            }
            else if (states[CurNode] == 1) {
                int length_node = pow(2, depth_max - depth);
                std::vector<std::vector<double>>
                        node_parent(decod_num, std::vector<double>(length_node)),
                        a(decod_num, std::vector<double>(length_node / 2)),
                        b(decod_num, std::vector<double>(length_node / 2));

                for (int i = 0; i < decod_num; i++) {
                    std::copy(L[i][depth].begin() + length_node*node,
                              L[i][depth].begin() + length_node *(node + 1), node_parent[i].begin());
                    std::copy(node_parent[i].begin(), node_parent[i].begin()+length_node/2, a[i].begin() );
                    std::copy(node_parent[i].begin()+ length_node/2, node_parent[i].end(), b[i].begin());
                }

                int left_child_depth = depth + 1;
                int left_child_node = node * 2;
                int left_length_node =  length_node / 2;
                std::vector<std::vector<double>> CurUCap(decod_num, std::vector<double>(left_length_node));

                for (int i = 0; i < decod_num; i++) {
                    std::copy(Ucap[i][left_child_depth].begin() + left_child_node*left_length_node,
                              Ucap[i][left_child_depth].begin() + left_length_node*(left_child_node+1), CurUCap[i].begin());
                }

                depth++; node = node * 2 + 1; length_node /= 2;
                std::vector<std::vector<double>> FuncG(decod_num);
                for (int i = 0; i < decod_num; i++) {
                    FuncG[i] = FuncGVectors(a[i], b[i], CurUCap[i]);
                    std::copy(FuncG[i].begin(), FuncG[i].end(), L[i][depth].begin() + length_node*node);
                }
                states[CurNode] = 2;
            }
            else if (states[CurNode] == 2){
                int length_node = pow(2, depth_max - depth);
                int gen_length_node = length_node / 2, gen_depth = depth + 1;
                int left_node = 2 * node, right_node = 2 * node + 1;
                std::vector<std::vector<int>>
                        Ucap_left (decod_num, std::vector<int>(gen_length_node)),
                        Ucap_right(decod_num, std::vector<int>(gen_length_node));

                for (int i = 0; i < decod_num; i++) {
                    std::copy(Ucap[i][gen_depth].begin() + gen_length_node*left_node,
                              Ucap[i][gen_depth].begin() + gen_length_node*(left_node + 1),
                              Ucap_left[i].begin());
                    std::copy(Ucap[i][gen_depth].begin() + gen_length_node*right_node,
                              Ucap[i][gen_depth].begin() + gen_length_node*(right_node + 1),
                              Ucap_right[i].begin());
                }

                std::vector<std::vector<int>> GetUcap(decod_num);
                for (int i = 0; i < decod_num; i++) {
                    GetUcap[i] = SumTwoVectors(Ucap_left[i], Ucap_right[i]);
                    std::copy(GetUcap[i].begin(), GetUcap[i].end(),
                              Ucap[i][depth].begin() + length_node*node);
                }
                node /= 2; depth--;
            }
        }
    }

    for (int i = 0; i < decod_num; i++) {
        std::vector<int> temp;
        for (int j = 0; j < N; j++) {
            if (IsFrozen[j] == 0) {
                temp.push_back(Answers[i][j]);
            } 
        }
        Answers[i] = temp;
    }


    return Answers;
}


int NumErrors(const std::vector<int>& Msg, const std::vector<int>& DecodWord) {
    int cnt_errors = 0;
    int num_iter = std::min(Msg.size(), DecodWord.size());
    for (int i = 0; i < num_iter; i++) {
        if (Msg[i] != DecodWord[i]) {
            cnt_errors++;
        }
    }
    return cnt_errors;
}
