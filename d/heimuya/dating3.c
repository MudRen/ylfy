//ROM dating
inherit ROOM;
void create()
{
        set("short", "������");
        set("long",
             "���ǡ�������̡��µ�������:�����õĴ�����ʮ������,�ֻ���һ������\n"
         "ʱ��ʱ�֡���������һ����(bian).\n"
        );
        set("exits", ([
                "south"      : __DIR__"chlang1",
                "northdown" : __DIR__"guang",
        ]));
        set("item_desc", ([
        "bian": "����д����������գ��������졣ǧ�����أ�һͳ���� ��\n",
        	]) );
        setup();
        replace_program(ROOM);
}
