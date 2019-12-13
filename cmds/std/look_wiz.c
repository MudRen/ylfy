
// look.c
#include <room.h>
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int look_room(object me, object env,int flag);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
varargs mixed classify_object(object obj,int flag);
string getper(object me, object obj);
string gettof(object me, object obj);
string getdam(object me, object obj);
string *tough_level_desc = ({
        BLU "����һ��" NOR,
        BLU "��������" NOR,
        BLU "����ҳ�" NOR,
        BLU "��ѧէ��" NOR,
        HIB "�����ž�" NOR,
        HIB "��֪һ��" NOR,
        HIB "����ͨͨ" NOR,
        HIB "ƽƽ����" NOR,
        HIB "ƽ������" NOR,
        HIB "��ͨƤë" NOR,
        HIB "��������" NOR,
        HIB "������" NOR,
        HIB "����С��" NOR,
        HIB "����С��" NOR,
        HIB "�������" NOR,
        CYN "�������" NOR,
        CYN "��Ȼ���" NOR,
        CYN "���д��" NOR,
        CYN "���д��" NOR,
        CYN "��Ȼ��ͨ" NOR,
        CYN "�������" NOR,
        CYN "�޿�ƥ��" NOR,
        CYN "����Ⱥ��" NOR,
        CYN "����似" NOR,
        CYN "�����뻯" NOR,
        CYN "����Ⱥ��" NOR,
        HIC "�Ƿ��켫" NOR,
        HIC "��������" NOR,
        HIC "һ����ʦ" NOR,
        HIC "�񹦸���" NOR,
        HIC "������˫" NOR,
        HIC "��������" NOR,
        HIC "������" NOR,
        HIC "��ز�¶" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        HIR "��ɲ�" NOR,
        BLU "����һ��" NOR,
});
string *heavy_level_desc= ({
        "����",
        "����",
        "����",
        "����",
        "����",
        "����",
        "����"
});

string *per_msg_male1 = ({
        CYN "Ӣ������,������档\n" NOR,
        CYN "��ò����,��Ŀ���ʡ�\n" NOR,
        CYN "����ΰ��Ӣͦ������֮�䣬��ɷ��\n" NOR,
        CYN "����Ӣΰ������������ȷʵ���������\n" NOR,
});

string *per_msg_male2 = ({
        CYN "Ӣ������,�������ʡ�\n" NOR,
        CYN "��ò���ڣ���Ŀ���ʡ�\n" NOR,
        CYN "��ò���棬���˷��ס�\n" NOR,
});
string *per_msg_male3 = ({
        CYN "��òƽƽ��ûʲô�ÿ��ġ�\n" NOR,
        CYN "��ò�׶��������⡣\n" NOR,
        CYN "�������ۣ��������硣\n" NOR,
        CYN "��òƽƽ��һ��һ�㡣\n" NOR,
});

string *per_msg_male4 = ({
        CYN "һ����������ӣ����������� \n" NOR,
        CYN "��ò�׺ݣ����ս�թ��\n" NOR,
        CYN "����һ�����Ѳ��ۣ��˾˲�����ģ����\n" NOR,
        CYN "��������ģ�һ���޾���ɵ�ģ���� \n" NOR, 
        CYN "������֣���ͷ������������˽�ı��ҡ� \n" NOR, 
});


string *per_msg_male61 = ({
        CYN "��ü��Ŀ�����˿��׿ɾ���\n" NOR,
});
string *per_msg_male62 = ({
        CYN "Ŀ����ͣ����˾���Զ֮��\n" NOR,
});

string *per_msg_female1 = ({
        CYN "�������ƣ�����ʤѩ����֪�㵹�˶���Ӣ�ۺ��ܡ� \n" NOR,
        CYN "������������Ŀ���飬����һЦ������������Ȼ�Ķ��� \n" NOR,
        CYN "�������֣��������ˣ��������Ҽ������� \n" NOR,
});

string *per_msg_female2 = ({
        CYN "��ɫ���������˴�Լ�� \n" NOR,
        CYN "�㷢��˿��������ѩ�� \n" NOR,
        CYN "������������Ŀ���顣 \n" NOR,
        CYN "�������֣��������ˡ� \n" NOR,
});

string *per_msg_female3 = ({
        CYN "���㲻�Ͼ������ˣ�Ҳ���м�����ɫ�� \n" NOR,
        CYN "���û�Ƿ���ʣ�ȷ���м��ݶ�����ɫ��  \n" NOR,
});
string *per_msg_female4 = ({
        CYN "���ñȽ��ѿ��� \n" NOR,
        CYN "���á���������  \n" NOR,
});

string *per_msg_female61 = ({
        CYN "��ü��Ŀ�����˿��׿ɾ���\n" NOR,
});
string *per_msg_female62 = ({
        CYN "Ŀ����ͣ����˾���Զ֮��\n" NOR,
});

string *per_msg_beast1 = ({
        CYN "�������ÿɰ�Ŷ�� \n" NOR,
        CYN "������������ϲ����  \n" NOR,
        CYN "�����ལ�����ϲ����\n" NOR,
});

string *per_msg_beast2 = ({
        CYN "���������������� \n" NOR,
        CYN "һ���װͰ͵����ӡ�  \n" NOR,
});

string *per_msg_beast3 = ({
        CYN "����ȥ���������ģ����Ǽ���û�Է������ӡ� \n" NOR,
        CYN "һ����ݺݵ����ӡ�  \n" NOR,
});

string *per_msg_beast4 = ({
        CYN "���ļ����ª���ǳ����˵ġ� \n" NOR,
        CYN "��ò�׶��������⣬����һ���;������֡�\n" NOR
});

string *per_msg_kid1 = ({
        CYN "��ü���ۣ�����ʮ�㡣\n" NOR,
        CYN "������ã���̬�Ƿ���\n" NOR,
        CYN "�������£�ɫ��������\n" NOR,
});

string *per_msg_kid2 = ({
        CYN "¡����ۣ���ɫ����\n" NOR,
        CYN "�����ལ�����ϲ����\n" NOR,
        CYN "ϸƤ���⣬�ڳ�������\n" NOR,
});

string *per_msg_kid3 = ({
        CYN "����󰫣�ɵ��ɵ����\n" NOR,
        CYN "�ʷ����֣�С��С�ۡ�\n" NOR,
        CYN "��ͷ���ԣ����ֱ��š�\n" NOR,
        CYN "��ͷ���ţ����Ƽ��ݡ�\n" NOR,
        CYN "����ľ�������в�ɫ��\n" NOR,
        CYN "��ٲ�������֫���ࡣ\n" NOR,
});

int abs(int x)
{
    if (x>=0) return x;
    else return -x;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

	if( !arg ) result = look_room(me, environment(me),0);
	else if(arg=="me") result=look_living(me, me);
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
    {
        if( obj->is_character() ) result = look_living(me, obj);
        else result = look_item(me, obj);
    }
	else result = look_room_item(me, arg);
    return result;
}

string look_fight(object me,object env,object * inv,mapping exits)
{
    object ot;
    int i,j;
    string str;
    str="";
    if(!me->query("env/olddisplay")) return "";//ȡ��
    //����������û������olddisplay�������,��ʾ�Է�Ը��ʹ�����ڵ�ս����ʾ.
    //��֮,���Ƿ���ԭ������ʾ.
    if (me->is_fighting())
    {
        mixed map;
        int mx,my;
        mx=env->get_matrix_x();
        my=env->get_matrix_y();
        map=allocate(mx*my);
        foreach(ot in inv)
        {
            if (ot->query_temp("map"))
            {
                if (ot->query_temp("map/x")<=mx
                &&ot->query_temp("map/x")>=1
                &&ot->query_temp("map/y")<=my
                &&ot->query_temp("map/y")>=1)
               map[ot->query_temp("map/x")-1+(ot->query_temp("map/y")-1)*mx]=ot->query("id");
            }
        }
        for(i=0;i<my;i++)
        {
        for(j=0;j<mx;j++)
        {
            if (map[i*mx+j])
            str+=sprintf(HIY"%|10.8s"NOR,map[i*mx+j]);
            else
            if (mapp(exits) && ( stringp(exits["west"]) && j==0 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["east"]) && j==mx-1 && abs((i+1)*2-my-1)<=1
              ||stringp(exits["north"]) && i==0 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["south"]) && i==my-1 && abs((j+1)*2-mx-1)<=1
              ||stringp(exits["southeast"]) && i==my-1 && j==mx-1
              ||stringp(exits["southwest"]) && i==my-1 && j==0
              ||stringp(exits["northeast"]) && i==0 && j==mx-1
              ||stringp(exits["northwest"]) && i==0 && j==0
              ))
                str+=sprintf(HIG"%|10s"NOR,"����");
            else
            str+=sprintf("%|10s","--");
        }
        str+="\n";
        }
    }
    //printf("\e[256D%s>" NOR, ctime(time())[11..18]);
	
	//return printf("\e[256D""%s",str );
    return str;
}

int look_room(object me, object env,int flag)
{
        int i;
        object *inv;
        mapping buffo = ([]), buffobj = ([]);
        string bfile, name;
        string stt;
        object ot;
        mixed coor;
        mapping exits;
        string str, *dirs;

        if (!userp(me) ) return 1;
        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲ��Ҳû�С�\n");
                return 1;
        }
//        if(!random(30))
//       "/adm/daemons/room"->add_file(file_name(env));
        name=env->query("outdoors");
        
	if(flag>3) return 1;
	if((!stringp(name)||NATURE_D->check_weather(name)==0)
            &&!env->query_temp("light")
    	    &&!wizardp(me))
        {
    		tell_object(me,"������ܻ����ɵ�һƬ�����ֲ�����ָ��\n"
                                "����ԼԼ�Ŀ������ڡ�\n");
    		if( mapp(exits = env->query("exits"))&&(flag<2) ) 
        	{
        		dirs = keys(exits);
        		for(i=0; i<sizeof(dirs); i++)
           			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
               				dirs[i] = 0;
               		dirs -= ({ 0 });
               		if( sizeof(dirs)==0 )
                   		str = "    ����û���κ����Եĳ�·��\n";
               		else if( sizeof(dirs)==1 )
                   		str = "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
               		else
                   		str = sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " +
                                                BOLD + "%s" + NOR + "��\n",
               		implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
         	}

    		if(str)
    			tell_object(me,str);
    		return 1;                           
   	}
	if(!arrayp(coor=env->query("coor"))) coor=({0,0,0});
    	str = sprintf(HIC "%s"NOR" - %s\n%s%s",
    	env->query("short"),
    	wizardp(me)? (file_name(env)+"\t����:\t"+(string)coor[0]+"\t"+coor[1]+"\t"+coor[2]): "",
    	(flag>0)?"":env->query("long"),
    	(env->query("outdoors")&&flag<1)? NATURE_D->outdoor_room_description(env) : "" );
    	exits = env->query("exits");
	if( mapp(exits)&&(flag<2) )
    	{
    		dirs = keys(exits);
        	for(i=0; i<sizeof(dirs); i++)
        	if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
             		dirs[i] = 0;
        	dirs -= ({ 0 });
                if( sizeof(dirs)==0 )
                	str += "    ����û���κ����Եĳ�·��\n";
                else if( sizeof(dirs)==1 )
                	str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                else
                	str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " +
                       BOLD + "%s" + NOR + "��\n",
                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
    	}

    	inv = all_inventory(env);
	if(flag>2) inv=({});
    	for(i=0; i<sizeof(inv); i++) 
        {
        	if( inv[i]==me ) continue;
        	if( inv[i]->query("no_shown")) continue;
        	if( !me->visible(inv[i]) ) continue;
           	if (userp(inv[i]))
              	{
                        str +="    "+inv[i]->short()+"\n";
              		continue;
              	}
            	bfile=base_name(inv[i])+"-$-"+inv[i]->short();
            	if ( member_array(bfile,keys(buffo)) == -1 )
                {
                	buffo[bfile]=1;
                 	buffobj[bfile]=inv[i];
                }
            	else 
                	buffo[bfile]+=1;
                
        }
        
	for (i=0 ; i <sizeof(keys(buffo)); i ++)
	{
    		stt = keys(buffo)[i];
    		ot = buffobj[stt];
    		if ( !objectp(ot) )  continue;
    		if ( ot ->query("combined_item") != 1 && buffo[stt] > 1 )
        		str+=sprintf("    %s%s",chinese_number(buffo[stt]),!ot->query("unit")?"��":ot->query("unit"))+ot->short()+"\n";
    		else str +="    "+ot->short()+"\n";
	}
    	str+=look_fight(me,env,inv,exits);
   	tell_object(me,str);
   	return 1;
}

int look_item(object me, object obj)
{
        mixed str;
        string prep;

                if(NATURE_D->check_weather()!=1
                        &&!environment(me)->query_temp("light")
                        &&!wizardp(me))
                        {
            tell_object(me,"������ܻ����ɵ�һƬ�����ֲ�����ָ��ʲôҲ��������\n");
            return 1;                           
                        }
        write(obj->long());
        str = classify_object(obj);
        if( stringp(str) && strlen(str)>1) {
                switch( (string)obj->query("prep") ) {
                        case "on":
                                prep = "��";
                                break;
                        case "under":
                                prep = "��";
                                break;
                        case "behind":
                                prep = "��";
                                break;
                        case "inside":
                                prep = "��";
                                break;
                        default:
                                prep = "��";
                                break;
                        }
                message("vision", sprintf("%s���У�\n  %s\n", prep,str ), me);
        }
        return 1;
}

string getper(object me, object obj)
{
        int spi,per,age;

        int weight;
        string str,race;

        per = obj->query_per();
        spi = me->query_spi();

// ���Բ���˿��Ĳ�׼
        if (spi>20) weight = 0;
        else weight = (int)(20 - spi)/4 ;

        if (random(10)>6) per = per - weight;
        else per = per + weight ;
    age=(obj->query_temp("apply/age")?
        obj->query_temp("apply/age"):obj->query("age"));
    race=(obj->query_temp("apply/race")?
        obj->query_temp("apply/race"):obj->query("race"));
    if ( race == "����" )
    {
        if ( obj->query_temp("apply/gender")== "����" ||
    (obj->query("gender")=="����"&&!obj->query_temp("apply/gender")))
        {
            if ( age > 60 )
                if ( per > 15 )
                    return ( per_msg_male61[random(sizeof(per_msg_male61))] );
                else
                    return ( per_msg_male62[random(sizeof(per_msg_male62))] );
            if ( age < 16 )
                {
                if(per>=15)
                    return ( per_msg_kid1[random(sizeof(per_msg_kid1))] );
                if(per>=10)
                    return ( per_msg_kid2[random(sizeof(per_msg_kid2))] );
                if(per<10)
                    return ( per_msg_kid3[random(sizeof(per_msg_kid3))] );
                }

            if ( per >= 20 )
                return ( per_msg_male1[random(sizeof(per_msg_male1))] );
            else if ( per >= 15 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))] );
            else if ( per >=10 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))] );
            else
                return ( per_msg_male4[random(sizeof(per_msg_male4))] );
        }
        if ( obj->query_temp("apply/gender")== "Ů��" ||
    (obj->query("gender")=="Ů��"&&!obj->query_temp("apply/gender")))
        {
            if ( age > 60 )
                if ( per > 15 )
                    return ( per_msg_female61[random(sizeof(per_msg_female61))] );
                else
                    return ( per_msg_female62[random(sizeof(per_msg_female62))] );
            if ( age < 16 )
                {
                if(per>=15)
                    return ( per_msg_kid1[random(sizeof(per_msg_kid1))] );
                if(per>=10)
                    return ( per_msg_kid2[random(sizeof(per_msg_kid2))] );
                if(per<10)
                    return ( per_msg_kid3[random(sizeof(per_msg_kid3))] );
                }
            if ( per >= 20 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))] );
            else if ( per >= 15 )
                return ( per_msg_female2[random(sizeof(per_msg_female2))] );
            else if ( per >=10 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))] );
            else 
                return ( per_msg_female4[random(sizeof(per_msg_female4))] );
        }
    }
    else if ( race == "Ұ��" )
    {
        if ( per >= 20 )
            return ( per_msg_beast1[random(sizeof(per_msg_beast1))] );
        else if ( per >= 10 )
            return ( per_msg_beast2[random(sizeof(per_msg_beast2))] );
        else if ( per < 10 )
            return ( per_msg_beast3[random(sizeof(per_msg_beast3))] );
    }
      if( !str) str="";
        return str;
}

string gettof(object me, object ob)
{
        object weapon;
        mapping prepare;
        string skill_type,desc;
        int attack_points,dodge_points,attack_lv,dodge_lv;
        if( objectp(weapon = ob->query_temp("weapon")) )
             skill_type = weapon->query("skill_type");
        else if (prepare&&sizeof(prepare)>0)
             skill_type = (keys(prepare))[0];
        else skill_type = "unarmed";
        attack_points = COMBAT_D->skill_power(ob, skill_type,
SKILL_USAGE_ATTACK);
        if(attack_points<0)attack_points=0;
        if(dodge_points<0 ) dodge_points=0;
        dodge_points  = COMBAT_D->skill_power(ob, "dodge"
,SKILL_USAGE_DEFENSE);
        attack_lv =to_int(sqrt(to_float(attack_points+1)))/8;
        dodge_lv  =to_int(sqrt(to_float(dodge_points+1)))/8;
        if(attack_lv>=sizeof(tough_level_desc))
             attack_lv =sizeof(tough_level_desc)-1;
        if( dodge_lv>=sizeof(tough_level_desc))
             dodge_lv =sizeof(tough_level_desc)-1;
        desc = "�������������"+tough_level_desc[((int)attack_lv)]
             +"��\n�������������"+ tough_level_desc[((int)dodge_lv)];
        return  desc;
}

int look_living(object me, object obj)
{
        string str,   pro;
        mixed *inv;
        mapping my_fam, fam;

                if(NATURE_D->check_weather()!=1
                        &&!environment(me)->query_temp("light")
                        &&!wizardp(me))
                        {
            tell_object(me,"������ܻ����ɵ�һƬ�����ֲ�����ָ��ʲôҲ��������\n");
            return 1;                           
                        }
        if( me!=obj )
                message("vision", me->name() + "�������㿴����֪����Щʲ�����⡣
\n", obj);

        str = obj->long();

        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
                str += sprintf("%s������Լ%s���ꡣ\n", pro, chinese_number(obj->query("age") / 10 * 10));
        if(obj->query("MarrY")&&obj->query("MarrY")==me->query("id"))
                {
                if(obj->query("gender")=="Ů��")
                    str+=sprintf(MAG"����������ӡ�\n"NOR);
                else 
                    str+=sprintf(MAG"��������ɷ�\n"NOR);
                }
    if(obj->is_character()&&!obj->is_corpse()){
                str+=getper(me,obj);
                str+=gettof(me,obj);
                str += sprintf("��\n");
                str +=sprintf("%s�ĳ����ƺ�",pro);
                str +=getdam(me,obj);
                str += sprintf("��\n");
    }
        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      mapp(my_fam = me->query("family"))
        &&      fam["family_name"] == my_fam["family_name"] ) {

                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "����" )
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }

        if( obj->query("max_kee") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100
/ (int)obj->query("max_kee")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1
);
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�
����\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me
        &&      living(obj)
        &&      random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
                COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("equipped") )
                str = HIC "  ��" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲ��Ҳû�С�\n");

        if(NATURE_D->check_weather()!=1
           &&!env->query_temp("light")
           &&!wizardp(me))
        {
        	tell_object(me,"������ܻ����ɵ�һƬ�����ֲ�����ָ��ʲôҲ��������\n");
            	return 1;                           
        }
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) 
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));

                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) 
        {
                if(objectp(exits[arg]))
                    look_room(me,exits[arg],0);
                 else if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env,0);
                else 
                {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]),0);
                }
                return 1;
        }
        if(wiz_level(me)>2 && env=find_player(arg))
        {
                look_room(me, environment(env),0);
                return 1;
        }

        return notify_fail("��Ҫ��ʲ�᣿\n");
}
string getdam(object me, object obj)
{

        int level;
        level = obj->query("force")/500+obj->query_str()+
    obj->query_temp("apply/damage")/10;
        level = level / 8;
                        if( level >= sizeof(heavy_level_desc) )
                                level = sizeof(heavy_level_desc)-1;
                        return heavy_level_desc[((int)level)];
}
varargs mixed classify_object(object obj,int flag)
{
        object *inv,ot;
        int i;
        string bfile,name,file_name,str,temp;
        mapping buffo=([]),buffobj=([]);
        
        str="";
        inv = all_inventory(obj);
        if( sizeof(inv)<1 )
                return 0;
        for(i=0; i<sizeof(inv); i++) 
        {
                if(inv[i]->query("no_shown")) continue;
                if (inv[i]->query("equipped"))
                {
                        temp = inventory_look(inv[i], flag);
                        if (stringp(temp)) str+=temp+"\n";
                        continue;
                }
                
                if ( flag==1 ) continue;

                bfile=base_name(inv[i])+"--"+inv[i]->short();
                if ( member_array(bfile,keys(buffo)) == -1 )
                {
                        buffo[bfile]=1;
                        buffobj[bfile]=inv[i];
                }
                else 
                {
                        buffo[bfile]+=1;
                }
                
        }
        
        for (i=0 ; i <sizeof(keys(buffo)); i ++)
        {
                sscanf(keys(buffo)[i],"%s--%s",file_name,name);
                ot = buffobj[keys(buffo)[i]];
                if ( !objectp(ot) ) 
                        continue;
                if ( ot ->query("combined_item") != 1 && buffo[keys(buffo)[i]] > 1 )
                        str+=sprintf("    %s%s",chinese_number(buffo[keys(buffo)[i]]),!ot->query("unit")?"��":ot->query("unit"))+ot->short()+"\n";
                else str +="    "+ot->short()+"\n";
        }

        return str;
}

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]

���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
�����look me����ô���Կ����Լ���

HELP
);
        return 1;
}
