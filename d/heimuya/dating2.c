//ROM dating
inherit ROOM;
void create()
{
        set("short", "�׻���");
        set("long",
             "���ǡ�������̡��µڶ�����:�׻��õĴ�������Ŀ��ȥ,һ����Ѫ,\n"
         "��������һ����(bian).���ϱ������м���Ѫ��(zi).\n"
        );
	
        set("exits", ([
                "west" : __DIR__"baistep1",
                "east" : __DIR__"linjxd6",
        ]));
 
                          
        set("item_desc", ([
        "bian": "����д�����������գ��׻����죻
          ǧ�����أ�һͳ���� ��\n",
        "zi" : "����д������ɽ���ӣ���ɱа�̡�\n" 
	]) );
        setup();
        
        replace_program(ROOM);
}
