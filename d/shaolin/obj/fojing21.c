// fojing21.c
inherit ITEM;
string* titles = ({
    "�����پ�",
    "������;�",
    "������",
    "��վ�",
    "�����۶��ľ�",
});
void create()
{
    set_name(titles[random(sizeof(titles))], ({ "shu", "book" }));
    set_weight(200);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "����һ��𾭡�\n");
        set("value", 500);
            set("shaolin",1);
        set("material", "paper");
        set("skill", ([
            "name": "buddhism", // name of the skill
            "exp_required": 0,  // minimum combat experience required
            "jing_cost":    20, // jing cost every time study this
            "difficulty":   20, // the base int to learn this skill
            "max_skill":    500 // the maximum level you can learn
        ]) );
    }
}


void init()
{
    if( this_player() == environment() )
    {
    add_action("do_study", "study",2);
    add_action("do_study", "du");
    }
}
int do_study(string arg)
{
    mapping skl;
    string *sname;
    int i, nf, nh;
    object me;
    me = this_player();
    if (!arg || arg !="jiafeng" )
	return notify_fail("��Ҫ��ʲô��\n");
    if (me->is_busy()){
        tell_object(me,"��������æ���ء�\n");
	return 1;
    }
    if ( me->query("marry") ){
        tell_object(me,"���Ѿ�����ɫ�䣬�޷���ѧϰ�����񹦣�\n");
	return 1;
    }
    if ( me->query("gender") != "����" ){
        tell_object(me,"���ͯ��֮�壬����ѧϰ�����񹦡�\n");
	return 1;
    }
    nf = (int)me->query_skill("force", 1);
    nh = (int)me->query_skill("jiuyang-shengong", 1);
    if ( nf < 10){
        tell_object(me,"��Ļ����ڹ���򻹲������޷��������񹦡�\n");
	return 1;
    }
    if (nf <= nh ){
        tell_object(me,"��Ļ����ڹ�������������ѧ��ȥ���߻���ħ�ġ�\n");
	return 1;
    }
    skl = me->query_skills();
    if (mapp(skl)){
	    sname  = keys(skl);
	    for (i=0;i<sizeof(skl);i++){
        	if (sname[i]=="hunyuan-yiqi") continue;
	        if (sname[i]=="jiuyang-shengong") continue;
        	if (sname[i]=="taiji-shengong") continue;
	            if( SKILL_D(sname[i])->valid_enable("force") ){
        		tell_object(me,"�㲻��ɢ�˱����ڹ�������ѧ�����񹦣���\n");
			return 1;
		    }
	    }
    }
    if ( me->is_fighter()){
	tell_object(me,"ս�����޷��Ķ���֪��\n");
	return 1;
    }
    me->receive_damage("jing", 20);
    if (nh<60)
    me->improve_skill("jiuyang-shengong", (me->query_skill("jiuyang-shengong")+me->query_int()));
    message_vision("$N����ר���ж��������ķ���\n", me);
    return 1;
}
int query_autoload() { return 1; }