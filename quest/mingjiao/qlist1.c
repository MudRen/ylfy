#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([      "quest":               "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":               "��ʦ��",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "Τ����",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([       "quest":               "����",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 350,
                "score" :               6
        ]),
        ([      "quest":                "�Ҳ�����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":               "����ɢ",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               12
        ]),
        ([      "quest":                "�ɺ�ҩ",
                "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "����ľ��",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               8
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               6
        ]), 

        ([      "quest":                "����ʤ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               8
        ]),
        ([      "quest":                "ľ���",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               6
        ]),    
        ([      "quest":                "��Ҷ",
                "quest_type":           "Ѱ",
                "time":                 550,
                "score" :               10
        ]),        
        ([      "quest":                YEL"ͭ��"NOR,
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),      
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               7
        ]),  
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               7
        ]),  
        ([      "quest":                "��Ƥ",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               4
        ]),
        ([      "quest":                "С̫��",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "Ѿ��",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "��֮��",
                "quest_type":           "ɱ",
                "time":                 520,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 280,
                "score" :               9
        ]),
        ([      "quest":               "ˮ��",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "��Ь",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               7
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
