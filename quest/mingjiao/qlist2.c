inherit SKILL;
#include <ansi.h>

mapping *quest = ({
        ([      "quest":               "Բ��",
                "quest_type":           "ɱ",
                "time":                 1200,
                "score" :               13
        ]),
        ([      "quest":                "���峬",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":                "����������",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               9
        ]),
        ([      "quest":               "������ʿ",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               7
        ]),
        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),       
        ([      "quest":                "����",
                  "quest_type":           "ɨ",
                "time":                 960,
                "score" :               6
        ]),
         ([      "quest":                "ׯ����",
                "quest_type":           "ɱ",
                "time":                 400,
                "score" :               5
        ]),    
        ([      "quest":                "������",
                "quest_type":           "ɨ",
                "time":                 960,
                "score" :               7
        ]),
        ([      "quest":                RED"ʥ����"NOR,
                "quest_type":           "ɨ",
                "time":                 260,
                "score" :               7
        ]),
        ([      "quest":                "���᷿",
                "quest_type":           "ɨ",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                "�����",
                "quest_type":           "ɨ",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                RED"������"NOR,
                "quest_type":           "ɨ",
                "time":                 260,
                "score" :               6
        ]),
        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 450,
                "score" :               7
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 800,
                "score" :               9
        ]),
        ([       "quest":               "֪�͵���",
                "quest_type":           "ɱ",
                "time":                 300,
                "score" :               6
        ]),

        ([      "quest":                "������",
                "quest_type":           "ɱ",
                "time":                 360,
                "score" :               7
        ]),
        ([      "quest":                "�Ҳ�����",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               9
        ]),  
        ([      "quest":                "��Ԫ��",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               10
        ]),
        ([      "quest":                "��ͯ",
                "quest_type":           "ɱ",
                "time":                 700,
                "score" :               6
        ]),
        ([      "quest":                "���촨",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               8
        ]),  
        ([      "quest":               "ҩ��",
                "quest_type":           "Ѱ",
                "time":                 500,
                "score" :               10
        ]),
        ([      "quest":                "��Ҷ",
                "quest_type":           "Ѱ",
                "time":                 450,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               7
        ]),  

        ([      "quest":                "������",
                "quest_type":           "Ѱ",
                "time":                 180,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "ǰ��",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "���䳡",
                "quest_type":           "ɨ",
                "time":                 200,
                "score" :               6
        ]),
        ([      "quest":                "���¾�����ʮ���¡�",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               7
        ]),
        ([      "quest":                "���¾����ڰ��¡�",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               7
        ]),
        ([      "quest":                "��˹����",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "�������䵶",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               6
        ]),
        ([      "quest":                "��",
                "quest_type":           "Ѱ",
                "time":                 480,
                "score" :               6
        ]),
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
