inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "������",
                "quest_type":           "Ѱ",
                "time":                 60,
                "score" :               2
        ]),
        ([      "quest":                "�̽�",
                "quest_type":           "Ѱ",
                "time":                 80,
                "score" :               2
        ]),
        ([      "quest":                "��å",
                "quest_type":           "ɱ",
                "time":                 200,
                "score" :               4
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 420,
                "score" :               10
        ]),
        ([      "quest":                "Сë¿",
                "quest_type":           "Ѱ",
                "time":                 420,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),       
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               5
        ]), 
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               5
        ]),  
 
        ([      "quest":                "��С��",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               8
        ]),
        ([      "quest":                "ţ��",
                "quest_type":           "ɨ",
                "time":                 1000,
                "score" :               5
        ]),
        ([      "quest":                "ţƤ�ƴ�",
                "quest_type":           "Ѱ",
                "time":                 130,
                "score" :               2
        ]), 
        ([      "quest":                "��Ϣ��",
                "quest_type":           "ɨ",
                "time":                 800,
                "score" :               6
        ]),
        ([      "quest":                "Ƥ����",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "ջ��",
                "quest_type":           "ɨ",
                "time":                 780,
                "score" :               5
        ]),
        ([      "quest":                HIY"�ϻ�ţ"NOR,
                "quest_type":           "Ѱ",
                "time":                 900,
                "score" :               4
        ]),  
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               9
        ]),
        ([      "quest":                "����",
                  "quest_type":           "Ѱ",
                "time":                 700,
                "score" :               4
        ]),
       ([      "quest":                "��ҩ",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               10
        ]),
       ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 200,
                "score" :               3
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 100,
                "score" :               5
        ]),

  });

mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

