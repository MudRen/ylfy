#include <ansi.h>
inherit SKILL;

mapping *quest = ({
        ([       "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               4
        ]),
        ([      "quest":                "��Ĺ",
                "quest_type":           "ɨ",
                "time":                 100,
                "score" :               5
        ]),
        ([      "quest":                "��Ʀ",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "����",
                  "quest_type":           "Ѱ",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               3
        ]),       
        ([      "quest":                "�ֵ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               2
        ]),  
        ([      "quest":                "��԰",
                  "quest_type":           "ɨ",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "Сë¿",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 120,
                "score" :               2
        ]),
         ([      "quest":               "Ƥ����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "����Ƭ",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               5
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               5
        ]),        
        ([      "quest":                "��ҩ",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               10
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "�廨��",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "ȭ���ܾ�",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 300,
                "score" :               6       
        ]),
        ([      "quest":                "ǰ��",
                "quest_type":           "ɨ",
                "time":                 300,
                "score" :               6
        ]),
    
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}


