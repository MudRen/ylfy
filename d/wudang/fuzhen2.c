// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz
inherit ROOM;
string* books = ({
    "laozi1",
    "daodejing-i",
    "laozi2",
    "daodejing-i",
    "laozi8",
    "daodejing-i",
    "laozi13",
    "laozi1",
    "laozi16",
    "daodejing-i",
    "laozi18"
});
void create()
{
    set("short", "����۶���");
    set("long", @LONG
�����Ǹ���۶��㣬���䵱�ղص��̵伮�ĵط�����ǽ��һ��
��ܣ������˵��̵ĵ伮��������һ�������εĴ����ӣ�����Ҳ��
�����顣һ����ͯ���������鼮��
LONG
    );
    set("exits", ([
        "westdown" : __DIR__"fuzhen1",
        "southup" : __DIR__"fuzhen3",
    ]));
    set("objects", ([
//                CLASS_D("wudang") + "/qingxu" : 1,
        __DIR__"obj/"+books[random(sizeof(books))] : 1,
        __DIR__"obj/"+books[random(sizeof(books))] : 1
    ]));
    setup();
    
}
int valid_leave(object me, string dir)
{
        mapping myfam;
    object ob;
    ob=present("qingxu", environment(me));
    if (objectp(ob) && living(ob)){
            myfam = (mapping)me->query("family");
            if ((!myfam || myfam["family_name"] != "�䵱��") && dir == "southup")
            return notify_fail("��������ȵ����㲻���䵱���ӣ��������ڡ�\n");
    }
        return ::valid_leave(me, dir);
}
