#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include <string.h>

void print_json(json_t *root);
void print_json_aux(json_t *element);
void print_json_object(json_t *element);
void print_json_array(json_t *element);
void print_json_string(json_t *element);
void print_json_integer(json_t *element);
void print_json(json_t *root) {
    print_json_aux(root);
}

void print_json_aux(json_t *element) {
    switch (json_typeof(element)) {
    case JSON_OBJECT:
        print_json_object(element);
        break;
    case JSON_ARRAY:
        print_json_array(element);
        break;
    case JSON_STRING:
        print_json_string(element);
        break;
    case JSON_INTEGER:
        print_json_integer(element);
        break;
    default:
        fprintf(stderr, "unrecognized JSON type %d\n", json_typeof(element));
    }
}

void print_json_object(json_t *element) {
    const char *key;
    json_t *value;
//	printf("{");
    json_object_foreach(element, key, value) {
        printf("{\"%s\" :", key);
        print_json_aux(value);
    }
}

void print_json_array(json_t *element) {
    size_t i;
    size_t size = json_array_size(element);
	printf("[");
    for (i = 0; i < size; i++) {
        print_json_aux(json_array_get(element, i)); 
 }
	printf("]");
}

void print_json_string(json_t *element) {
    printf(" %s}\n", json_string_value(element));
}

void print_json_integer(json_t *element) {
    printf("%" JSON_INTEGER_FORMAT "},\n", json_integer_value(element));
}

int main(){
	FILE *fp;
	fp = fopen("/etc/protocols","r");
	fseek(fp, 302, SEEK_CUR);
	char *p, buff[250], dtm[250],protocol[40], ignore[100], ignore1[100];
	int index;
	json_t * array1 = json_array();
	json_t * object = json_object();
	const char *key = "obj";
	json_t * array = json_array();
	json_object_set(object,key,array);
	p = fgets(buff, 250, fp);
	while(p!='\0'){	
	json_t * object1 = json_object();
        json_t * object2 = json_object();
	strcpy(dtm,buff);
	sscanf(dtm, "%s %d %s %s", protocol, &index, ignore, ignore1 );
	const char *key1 = "Protocol";
	json_t * value1 = json_string(protocol);
	const char *key2 = "index";
	json_t * value2 = json_integer(index);	
	json_object_set_new(object1, key1, value1);
	json_object_set_new(object2, key2, value2);
	json_array_append(array,object1);
	json_array_append(array,object2);
	p = fgets(buff, 250, fp); 	
 }	
	json_dump_file(object, "/home/saurabh/make1.json", 0);
	print_json(object);
	json_decref(array);
	json_decref(object);
	return 0;
}










                                  
