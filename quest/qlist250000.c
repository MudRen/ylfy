mapping *quest = ({
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "�һ���",
        "diff":                 4,
        ]),
     ([      "quest":                "��ľ��",
        "diff":                 5,
        ]),
     ([      "quest":                "���������Ͼ�",
        "diff":                 2,
        ]),
     ([      "quest":                RED "��ö��" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                MAG "������" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "���¾�����һ�¡�",
        "diff":                 2,
        ]),
        
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
