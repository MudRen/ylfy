// tynroad.c ��԰С·
// by Marz 
inherit ROOM;
string* npcs = ({
    "little_monkey",
    "monkey",
    "little_monkey",
    "little_bee",
    "bee",
    "little_bee",
});
                                
void create()
{
    int i = random(sizeof(npcs));
        
    set("short", "��԰С·");
    set("long", @LONG
��ǰ��Ȼ���ʣ������ɵ�������԰�ߵ�С·�ϡ�·����Ӣ�ͷף�һ���������֣�
ʢ���ŷۺ���һ�������һƬ���������ߡ������Կ����۷䡸���ˡ����ڻ������
����æ����ͣ�������Գ���ߴզ����������䵱ɽ�е�һ��С·��
LONG
    );
    set("outdoors", "wudang");
    set("exits", ([
        "south" : __DIR__"taiziyan",
        "west" : __DIR__"nanyan",
        "east" : __DIR__"shesheng",
    ]));
    
    set("objects", ([
        __DIR__"npc/"+npcs[i] : 1]));
            
    setup();
}
