//ROM dating
inherit ROOM;
void create()
{
        set("short", "������");
        set("long",
             "���ǡ�������̡��µ��Ĵ���:�����õĴ�����ԶԶ��ȥ�������죬���Ʋ�\n"
         "ʳ�˼��̻���������һ����(bian).\n"
        );
	
        set("exits", ([
                "west" : __DIR__"road1",
//                "southup" : __DIR__"tian1",
        ]));
 
                          
        set("item_desc", ([
        "bian": "����д����������---�������ʥ��ס�ء�\n",
        	]) );
        setup();
        
        replace_program(ROOM);
}
