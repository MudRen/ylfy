mapping *quest = ({
     ([      "quest":                "���ߵ�",
        "diff":                 2,
        ]),
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "�ֲ���",
        "diff":                 2,
        ]),
     ([      "quest":                "������",
        "diff":                 2,
        ]),
     ([      "quest":                "�׷�",
        "diff":                 2,
        ]),
     ([      "quest":                HIC "��ɫ����" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "���¾�����ʮ���¡�",
        "diff":                 2,
        ]),
        
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
